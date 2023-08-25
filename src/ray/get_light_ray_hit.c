/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_ray_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/25 13:44:20 by dpalmer          ###   ########.fr       */
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
		temp = v3d_subtract(&shadow.origin, &temp_impact.point);
		shadow.direction = v3d_unit_vector(&temp);
		if (ray_hit(scene, &temp_impact, &shadow))
		{
			temp_impact.normal = get_object_normal(\
				&scene->objects[impact->index], &temp_impact.point);
			color_light(&scene->lights[index], &temp_impact, &light, &shadow);
		}
		index++;
	}
	return (light);
}
