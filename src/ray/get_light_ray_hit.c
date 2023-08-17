/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_ray_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/17 15:25:51 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "parser.h" //delete me
#include <stdio.h> //delete me

static BOOL	color_light(
	t_scene *scene,
	t_impact *impact,
	t_light *light,
	int index)
{
	t_color	color;

	color = (t_color){0, 0, 0};
	//TODO: calculate the color of the light ray and update t_light
}

static BOOL	check_closest(
	t_scene *scene,
	t_impact *impact,
	t_ray temp,
	int index)
{
	double		light_dist;
	t_v3d		temp_dist;
	t_impact	temp_impact;
	BOOL		result;
	int			i;

	i = 0;
	result = FALSE;
	temp_dist = (v3d_subtract(&scene->lights[index].location, &impact->point));
	light_dist = v3d_get_magnitude(temp_dist);
	temp.direction = v3d_unit_vector(&temp_dist);
	while (index < scene->n_objects)
	{
		if (ray_hit_shapes(&temp_impact, &scene->objects[index], &temp))
		{
			result = TRUE;
			if (temp_impact.distance < light_dist)
				return (FALSE);
		}
	}
	return (result);
}

t_light	check_light(t_scene *scene, t_impact *impact)
{
	t_ray	temp;
	t_light	light;
	int		index;

	index = 0;
	ft_bzero(&light, sizeof(t_light));
	temp.origin = impact->point;
	light.color = (t_color){0, 0, 0};
	while (index < scene->n_lights)
	{
		if (check_closest(scene, impact, temp, index))
			color_light(scene, impact, &light, index);
		index++;
	}
	return (light);
}
