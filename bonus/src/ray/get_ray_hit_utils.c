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
BOOL	get_closest_t(
	double t0,
	double t1,
	double *impact_time)
{
	if (t0 < EPSILON && t1 < EPSILON)
		return (FALSE);
	if (t1 > EPSILON)
		*impact_time = t1;
	else
		*impact_time = t0;
	return (TRUE);
}

BOOL	is_inside_cylinder(
	t_v3d *point,
	t_object *cylinder)
{
	t_v3d	bottom;
	t_v3d	temp;
	double	projection;

	bottom = get_shape_bottom(cylinder);
	temp = v3d_subtract(point, &bottom);
	projection = v3d_dot(&temp, &cylinder->axis);
	if (projection < 0 || projection > cylinder->height)
		return (FALSE);
	if (v3d_length_squared(&temp) - pow(projection, 2) \
		< pow(cylinder->radius, 2))
		return (TRUE);
	return (FALSE);
}
