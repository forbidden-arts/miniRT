/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:16:51 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/13 14:34:08 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "v3d.h"
#include "render.h"

BOOL	get_ray_hit_shapes(t_impact *temp_impact, t_object *object, t_ray *ray)
{
	BOOL	result;

	result = FALSE;
	if (object->type == SPHERE)
		result = get_ray_hit_sphere(temp_impact, object, ray);
	else if (object->type == PLANE)
		result = get_ray_hit_plane(temp_impact, object, ray);
	else if (object->type == CYLINDER)
		result = get_ray_hit_cylinder(temp_impact, object, ray);
	return (result);
}

void	copy_impact_data(t_impact *impact_src, t_impact *impact_dst)
{
	impact_dst->object_type = impact_src->object_type;
	impact_dst->object = impact_src->object;
	impact_dst->distance = impact_src->distance;
	impact_dst->point = impact_src->point;
	impact_dst->normal = impact_src->normal;
}

/*	This function is for finding out if the ray hits an object.

	Will iterate through all shapes and check if a ray hits a shape (ie. object).

	If the ray hits a shape, the closest ray hit will be stored into
	the impact struct given as an argument and func will return TRUE.*/
BOOL	get_ray_hit(t_scene *scene, t_impact *impact, t_ray *ray)
{
	t_impact	temp_impact;
	BOOL		ray_hit;
	int			i;

	ray_hit = FALSE;
	i = 0;
	while (i < scene->n_objects)
	{
		if (get_ray_hit_shapes(&temp_impact, &scene->objects[i], ray) == TRUE)
		{
			if (ray_hit == FALSE)
				copy_impact_data(&temp_impact, impact);
			else
			{
				if (temp_impact.distance < impact->distance)
					copy_impact_data(&temp_impact, impact);
			}
			ray_hit = TRUE;
		}
		i++;
	}
	return (ray_hit);
}
