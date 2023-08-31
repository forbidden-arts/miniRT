/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:29:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/31 11:03:02 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"

BOOL	is_impact_on_cylinder_cap(
	t_object *cylinder,
	t_v3d *impact,
	BOOL *top_cap)
{
	t_v3d	cap_center;
	double	distance_to_cap_center;

	if (is_point_closer_to_top_cap(cylinder, impact, &cap_center))
		*top_cap = TRUE;
	else
		*top_cap = FALSE;
	distance_to_cap_center = v3d_get_dist(impact, &cap_center);
	if (distance_to_cap_center <= cylinder->radius)
		return (TRUE);
	return (FALSE);
}

t_v3d	get_cylinder_normal(
	t_object *cylinder,
	t_v3d *impact)
{
	t_v3d	temp;
	double	distance_along_axis;
	BOOL	top_cap;

	if (is_impact_on_cylinder_cap(cylinder, impact, &top_cap))
	{
		if (top_cap)
			return (v3d_multiply_scalar(&cylinder->axis, -1));
		return (cylinder->axis);
	}
	temp = v3d_subtract(impact, &cylinder->point);
	distance_along_axis = v3d_dot(&temp, &cylinder->axis);
	temp = v3d_multiply_scalar(&cylinder->axis,
			distance_along_axis);
	temp = v3d_add(&cylinder->point, &temp);
	return (v3d_subtract(&temp, impact));
}

BOOL	is_impact_on_cone_cap(
	t_object *cone,
	t_v3d *impact)
{
	t_v3d	cap_center;
	t_v3d	temp;
	double	distance_impact;

	cap_center = get_shape_bottom(cone);
	temp = v3d_subtract(impact, &cap_center);
	distance_impact = v3d_dot(&temp, &cone->axis);
	if (fabs(distance_impact) <= EPSILON)
		if (v3d_length(&temp) <= cone->radius)
			return (TRUE);
	return (FALSE);
}

t_v3d	get_cone_normal(
	t_object *cone,
	t_v3d *impact)
{
	t_v3d	cone_impact;
	t_v3d	normal;

	if (is_impact_on_cone_cap(cone, impact))
		return (v3d_multiply_scalar(&cone->axis, 1));
	cone_impact = v3d_subtract(&cone->point, impact);
	normal = v3d_cross(&cone_impact, &cone->axis);
	normal = v3d_cross(&cone_impact, &normal);
	return (normal);
}

t_v3d	get_object_normal(
	t_object *object,
	t_v3d *impact)
{
	t_v3d	normal;

	if (object->type == SPHERE)
		normal = v3d_subtract(&object->point, impact);
	if (object->type == CYLINDER)
		normal = get_cylinder_normal(object, impact);
	if (object->type == PLANE)
		normal = v3d_multiply_scalar(&object->axis, -1);
	if (object->type == CONE)
		normal = get_cone_normal(object, impact);
	normal = v3d_unit_vector(&normal);
	return (normal);
}
