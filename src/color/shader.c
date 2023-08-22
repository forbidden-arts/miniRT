/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:12:26 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/22 14:35:52 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "v3d.h"
#include "scene.h"
#include "ray.h"

#define AMB 0
#define DIF 1
#define RES 2

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
	ray_init_with_values(ray, &impact->point, &normal);
}

// ADD ME LATER
// color[DIF] = v3d_multiply_scalar(&light->color, light->intensity);
t_color	shade_hit(
	t_scene *scene,
	t_impact *impact)
{
	t_color	color[3];

	ft_bzero(color, 3 * sizeof(t_v3d));
	color[AMB] = v3d_multiply_scalar(&scene->ambient.color,
			scene->ambient.intensity);
	color[AMB] = v3d_multiply(&impact->color, &color[AMB]);
	color[RES] = v3d_add(&color[AMB], &color[DIF]);
	return (color[RES]);
}
