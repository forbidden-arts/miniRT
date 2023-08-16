/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:16:51 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/16 14:09:08 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "v3d.h"
#include "render.h"

static BOOL	ray_hit_shapes(t_impact *temp, t_object *object, t_ray *ray)
{
	BOOL	result;

	result = FALSE;
	if (object->type == SPHERE)
		result = ray_hit_sphere(temp, object, ray);
	else if (object->type == PLANE)
		result = ray_hit_plane(temp, object, ray);
	else if (object->type == CYLINDER)
		result = ray_hit_cylinder(temp, object, ray);
	return (result);
}

static void	dup_impact(t_impact *src, t_impact *dst)
{
	dst->object_type = src->object_type;
	dst->object = src->object;
	dst->distance = src->distance;
	dst->point = src->point;
	dst->normal = src->normal;
	dst->to_source = src->to_source;
}

/*	This function is for finding out if the ray hits an object.

	Will iterate through all shapes and check if a ray hits a shape (ie. object).

	If the ray hits a shape, the closest ray hit will be stored into
	the impact struct given as an argument and func will return TRUE.*/
BOOL	ray_hit(t_scene *scene, t_impact *impact, t_ray *ray)
{
	t_impact	temp_impact;
	BOOL		ray_hit;
	size_t		i;

	ray_hit = FALSE;
	i = 0;
	while (i < scene->n_objects)
	{
		if (ray_hit_shapes(&temp_impact, &scene->objects[i], ray))
		{
			if (!ray_hit || temp_impact.distance < impact->distance)
				dup_impact(&temp_impact, impact);
			ray_hit = TRUE;
		}
		i++;
	}
	return (ray_hit);
}
