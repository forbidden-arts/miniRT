/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:12:26 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/17 12:50:54 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "v3d.h"
#include "scene.h"
#include "ray.h"

#define AMB 0
#define DIF 1
#define RES 2

#include <stdio.h>
#include "parser.h"

void	create_light_ray(
	t_scene *scene,
	t_impact *impact,
	size_t index,
	t_ray *ray)
{
	t_v3d	direction;
	t_v3d	normal;

	direction = v3d_subtract(&impact->point, &scene->lights[index].location);
	normal = v3d_unit_vector(&direction);
	ray_init_with_values(ray, &scene->lights[index].location, &normal);
}

t_color	shade_hit(t_scene *scene, t_impact *impact)
{
	t_color	color[3];
	size_t	index;
	t_ray	ray;

	index = 0;
	ft_bzero(color, 3 * sizeof(t_v3d));
	color[AMB] = v3d_multiply_scalar(&scene->ambient.color,
			scene->ambient.intensity / 100.0);
	color[AMB] = v3d_multiply(&impact->color, &color[AMB]);
	while (index < (size_t)scene->n_lights)
	{
		create_light_ray(scene, impact, index, &ray);
		// printf("\nray origin:");
		// print_v3d_data(&ray.origin);
		// printf("\nray direction:");
		// print_v3d_data(&ray.direction);
		if (get_light_ray_hit(scene, impact, &ray))
				color[DIF] = v3d_multiply(&impact->color,
					&scene->lights[index].color);
		color[RES] = v3d_add(&color[RES], &color[DIF]);
		index++;
	}
	color[RES] = v3d_multiply_scalar(&color[RES],
			(double)scene->lights[index].intensity / 100);
	color[RES] = v3d_add(&color[AMB], &color[RES]);
	return (color[RES]);
}
