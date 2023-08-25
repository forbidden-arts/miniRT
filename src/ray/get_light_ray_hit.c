/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_ray_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/25 11:30:23 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	color_light(
	t_scene *scene,
	t_impact *impact,
	t_ray *shadow,
	int index)
{
	t_light	temp;
	t_color	color;

	temp = scene->lights[index];
	temp.intensity = fmax(v3d_dot(&impact->normal, &shadow->direction) * -1, 0);
	temp.color = v3d_multiply(&temp.color, &impact->color);
	color = v3d_multiply_scalar(&temp.color, temp.intensity);
	impact->color = v3d_add(&impact->color, &color);
}

static void	check_closest(
	t_scene *scene,
	t_impact *impact,
	t_ray *shadow,
	int index)
{
	double		light_dist;
	t_v3d		temp_dist;
	t_impact	temp_impact;
	BOOL		result;
	int			i;

	i = 0;
	result = FALSE;
	temp_dist = (v3d_subtract(&impact->point, &scene->lights[index].location));
	light_dist = v3d_get_dist(&impact->point, &scene->lights[index].location);
	shadow->origin = scene->lights[index].location;
	shadow->direction = v3d_unit_vector(&temp_dist);
	while (i < scene->n_objects)
	{
		if (ray_hit_shapes(&temp_impact, &scene->objects[i], shadow))
		{
			if (fabs(temp_impact.time - light_dist) < EPSILON)
				color_light(scene, impact, shadow, index);
		}
		i++;
	}
}

void	check_light(
	t_scene *scene,
	t_impact *impact)
{
	t_ray	shadow;
	int		index;

	index = 0;
	while (index < scene->n_lights)
	{
		check_closest(scene, impact, &shadow, index);
		index++;
	}
}
