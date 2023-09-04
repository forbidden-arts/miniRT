/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:29:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/09/04 18:00:36 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"

t_v3d	get_sphere_normal(
	t_object *sphere,
	t_v3d *impact)
{
	if (v3d_get_dist(&sphere->point, impact) < sphere->radius)
		return (v3d_subtract(impact, &sphere->point));
	return (v3d_subtract(&sphere->point, impact));
}

t_v3d	get_cylinder_normal(
	t_object *cylinder,
	t_v3d *impact)
{
	t_v3d	temp;
	double	distance_along_axis;
	BOOL	top_cap;
	BOOL	cyl_inside;

	cyl_inside = is_inside_cylinder(impact, cylinder);
	if (is_impact_on_cylinder_cap(cylinder, impact, &top_cap))
	{
		if ((top_cap && !cyl_inside) || (!top_cap && cyl_inside))
			return (v3d_multiply_scalar(&cylinder->axis, -1));
		return (cylinder->axis);
	}
	temp = v3d_subtract(impact, &cylinder->point);
	distance_along_axis = v3d_dot(&temp, &cylinder->axis);
	temp = v3d_multiply_scalar(&cylinder->axis,
			distance_along_axis);
	temp = v3d_add(&cylinder->point, &temp);
	if (cyl_inside)
		return (v3d_subtract(impact, &temp));
	return (v3d_subtract(&temp, impact));
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

t_v3d	get_plane_normal(
	t_v3d *plane_axis,
	t_impact *impact)
{
	if (v3d_dot(plane_axis, &impact->to_source) < EPSILON)
		return (v3d_multiply_scalar(plane_axis, -1));
	return (*plane_axis);
}

t_v3d	get_object_normal(
	t_object *object,
	t_impact *impact)
{
	t_v3d	normal;

	if (object->type == SPHERE)
		normal = get_sphere_normal(object, &impact->point);
	if (object->type == CYLINDER)
		normal = get_cylinder_normal(object, &impact->point);
	if (object->type == PLANE)
		normal = get_plane_normal(&object->axis, impact);
	if (object->type == CONE)
		normal = get_cone_normal(object, &impact->point);
	normal = v3d_unit_vector(&normal);
	return (normal);
}
