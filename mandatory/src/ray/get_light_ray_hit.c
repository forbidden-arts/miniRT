/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_ray_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/29 10:25:20 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "shapes.h"

static void	color_light(
	t_light *original,
	t_impact *impact,
	t_light *light,
	t_ray *shadow)
{
	t_color	color;

	light->intensity += fmax(v3d_dot(&impact->normal, &shadow->direction) \
		* original->intensity, 0);
	color = v3d_multiply_scalar(&original->color, light->intensity);
	v3d_add_in_place(&light->color, &color);
}

t_light	check_light(
	t_scene *scene,
	t_impact *impact)
{
	t_impact	temp_impact;
	t_light		light;
	t_ray		shadow;
	t_v3d		temp;
	int			index;

	index = 0;
	ft_bzero(&light, sizeof(t_light));
	while (index < scene->n_lights)
	{
		shadow.origin = scene->lights[index].location;
		temp = v3d_subtract(&impact->point, &shadow.origin);
		shadow.direction = v3d_unit_vector(&temp);
		if (ray_hit(scene, &temp_impact, &shadow) \
			&& fabs(v3d_get_dist(&shadow.origin, &impact->point) \
			- temp_impact.time) <= EPSILON)
		{
			color_light(&scene->lights[index], impact, &light, &shadow);
		}
		index++;
	}
	return (light);
}
