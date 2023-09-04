/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:29:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/09/04 12:48:13 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"

t_v3d	get_sphere_normal(
	t_object *sphere,
	t_v3d *impact)
{
	return (v3d_subtract(&sphere->point, impact));
}

t_v3d	get_cylinder_normal(
	t_object *cylinder,
	t_v3d *impact)
{
	t_v3d	temp;
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
		normal = object->axis;
	if (object->type == CONE)
		normal = get_cone_normal(object, impact);
	normal = v3d_unit_vector(&normal);
	return (normal);
}
