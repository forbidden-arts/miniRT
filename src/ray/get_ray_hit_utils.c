/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:14:40 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/16 14:38:48 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "ray.h"

/*	This function gets the closest quadratic equation solution (t0 or t1).
	If both values are negative we know that both intersection "points" are
	behind the ray, but if one of the solutions is positive
	and the other is negative, we know that the ray's origin is inside whatever
	shape we are currently checking and we use the positive one. */
BOOL	get_closest_t(double t0, double t1, t_impact *impact)
{
	if (t0 < EPSILON && t1 < EPSILON)
		return (FALSE);
	if (t1 > EPSILON)
		impact->time = t1;
	else
		impact->time = t0;
	return (TRUE);
}

/*	This function calculates the impact point where the ray intersects with
	a surface. */
t_v3d	get_impact_point(t_v3d *ray_origin, t_v3d *ray_direction,
	double t_parameter)
{
	t_v3d	offset_along_ray;

	offset_along_ray = v3d_multiply_scalar(ray_direction, t_parameter);
	return (v3d_add(ray_origin, &offset_along_ray));
}

/*	This function is used to calculate the surface normal for a sphere. */
t_v3d	get_impact_normal(t_object *object,	t_v3d *impact)
{
	t_v3d	normal;

	if (object->type == SPHERE)
		normal = v3d_subtract(impact, &object->point);
	return (v3d_unit_vector(&normal));
}
