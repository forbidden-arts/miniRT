/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:29:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/09/04 12:28:55 by dpalmer          ###   ########.fr       */
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

t_v3d	get_plane_normal(
	t_object *plane,
	t_v3d *impact)
{
	if (v3d_dot(&plane->axis, impact) < EPSILON)
		return (v3d_multiply_scalar(&plane->axis, -1));
	return (plane->axis);
}

t_v3d	get_cylinder_normal(
	t_object *cylinder,
	t_v3d *impact)
{
	t_v3d	temp;
	t_v3d	to_axis;
	t_v3d	to_axis_norm;
	double	distance_along_axis;

	if (is_impact_on_cylinder_cap(cylinder, impact))
	{
		if (v3d_dot(&cylinder->axis, impact) < EPSILON)
			return (v3d_multiply_scalar(&cylinder->axis, -1));
		return (cylinder->axis);
	}
	temp = v3d_subtract(impact, &cylinder->point);
	distance_along_axis = v3d_dot(&temp, &cylinder->axis);
	temp = v3d_multiply_scalar(&cylinder->axis,
			distance_along_axis);
	temp = v3d_add(&cylinder->point, &temp);
	to_axis = v3d_subtract(&temp, impact);
	to_axis_norm = v3d_unit_vector(&to_axis);
	if (v3d_dot(&to_axis, &to_axis_norm) > 0)
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

t_v3d	get_object_normal(
	t_object *object,
	t_v3d *impact)
{
	t_v3d	normal;

	if (object->type == SPHERE)
		normal = get_sphere_normal(object, impact);
	if (object->type == CYLINDER)
		normal = get_cylinder_normal(object, impact);
	if (object->type == PLANE)
		normal = get_plane_normal(object, impact);
	if (object->type == CONE)
		normal = get_cone_normal(object, impact);
	normal = v3d_unit_vector(&normal);
	return (normal);
}
