/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_ray_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/14 16:21:48 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*	This function is for checking if the point3 values are the same. Used
	to check if the light ray hits the impact point unimpeded.*/
BOOL	compare_v3d(t_v3d *first, t_v3d *second)
{
	t_v3d	result;

	result = v3d_subtract(first, second);
	if (&result == &(t_v3d){0, 0, 0})
		return (TRUE);
	return (FALSE);
}

BOOL	compare_normals(t_v3d *first, t_v3d *second)
{
	if (v3d_dot(first, second) > 0.0)
		return (TRUE);
	return (FALSE);
}

/*	This function is for finding out if the light ray will hit the impact point
	unimpeded.

	Before calling this function you will have to initialize the light ray.
	*/
BOOL	get_light_ray_hit(t_scene *scene, t_impact *impact,
	t_ray *light_ray)
{
	BOOL		result;
	t_impact	light_impact;

	get_ray_hit(scene, &light_impact, light_ray);
	result = compare_v3d(&impact->point, &light_impact.point);
	if (result == TRUE)
		if (compare_normals(&scene->cameras[0].direction, &impact->normal)
			!= compare_normals(&light_ray->direction, &impact->normal))
			return (FALSE);
	return (result);
}