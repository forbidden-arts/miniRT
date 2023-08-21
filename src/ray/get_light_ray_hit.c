/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_ray_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/21 12:46:16 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

#include "parser.h" //delete me
#include <stdio.h> //delete me

static void	color_light(
	t_scene *scene,
	t_light *light,
	int index)
{
	t_light	temp;
	t_color	color;

	temp = scene->lights[index];
	color = v3d_multiply_scalar(&temp.color, temp.intensity);
	printf("\nColor light adj: ");
	print_v3d_data(&color);
	light->color = v3d_add(&light->color, &color);
}

static BOOL	check_closest(
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
			result = TRUE;
			if (temp_impact.time < light_dist)
				return (FALSE);
		}
		i++;
	}
	return (result);
}

t_light	check_light(t_scene *scene, t_impact *impact)
{
	t_ray	shadow;
	t_light	light;
	int		index;

	index = 0;
	ft_bzero(&light, sizeof(t_light));
	light.color = (t_color){0, 0, 0};
	while (index < scene->n_lights)
	{
		if (check_closest(scene, impact, &shadow, index))
		{
			color_light(scene, &light, index);
		}
		index++;
	}
	return (light);
}
