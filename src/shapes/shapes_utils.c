/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:29:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/28 13:03:41 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"

BOOL	is_impact_on_cylinder_cap(
	t_object *cylinder,
	t_v3d *impact,
	BOOL *top_cap)
{
	t_v3d	cap_center;
	double	distance_to_cap_center;

	if (is_point_closer_to_top_cap(cylinder, impact, &cap_center))
	{
		*top_cap = TRUE;
		distance_to_cap_center = v3d_get_dist(impact, &cap_center);
		if (distance_to_cap_center <= cylinder->radius
			&& impact->e[2] >= cylinder->point.e[2]
			&& impact->e[2] <= cylinder->point.e[2] + cylinder->height * 0.5)
			return (TRUE);
	}
	else
	{
		*top_cap = FALSE;
		distance_to_cap_center = v3d_get_dist(impact, &cap_center);
		if (distance_to_cap_center <= cylinder->radius
			&& impact->e[2] >= cylinder->point.e[2]
			&& impact->e[2] <= cylinder->point.e[2] + cylinder->height * -0.5)
			return (TRUE);
	}
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
			return (cylinder->axis);
		else
			return (v3d_multiply_scalar(&cylinder->axis, -1));
	}
	temp = v3d_subtract(impact, &cylinder->point);
	distance_along_axis = v3d_dot(&temp, &cylinder->axis);
	temp = v3d_multiply_scalar(&cylinder->axis,
			distance_along_axis);
	temp = v3d_add(&cylinder->point, &temp);
	return (v3d_subtract(impact, &temp));
}

BOOL	is_impact_on_cone_cap(
	t_object *cone,
	t_v3d *impact)
{
	t_v3d	cap_center;
	double	distance_to_cap_center;

	cap_center = get_shape_bottom(cone);
	distance_to_cap_center = v3d_get_dist(impact, &cap_center);
	if (distance_to_cap_center <= cone->radius
		&& impact->e[2] >= cone->point.e[2]
		&& impact->e[2] <= cone->point.e[2] + cone->height * -0.5)
		return (TRUE);
	return (FALSE);
}

t_v3d	get_cone_normal(
	t_object *cone,
	t_v3d *impact)
{
	t_v3d	temp1;
	t_v3d	temp2;
	double	distance_along_axis;

	if (is_impact_on_cone_cap(cone, impact))
		return (v3d_multiply_scalar(&cone->axis, -1));
	temp1 = get_shape_bottom(cone);
	temp1 = v3d_subtract(impact, &temp1);
	distance_along_axis = v3d_dot(&temp1, &cone->axis);
	temp2 = v3d_multiply_scalar(&cone->axis, distance_along_axis);
	return (v3d_subtract(&temp1, &temp2));
}

t_v3d	get_object_normal(
	t_object *object,
	t_v3d *impact)
{
	t_v3d	normal;

	if (object->type == SPHERE)
		normal = v3d_subtract(impact, &object->point);
	if (object->type == CYLINDER)
		normal = get_cylinder_normal(object, impact);
	if (object->type == PLANE)
		normal = object->axis;
	if (object->type == CONE)
		normal = get_cone_normal(object, impact);
	v3d_unit_vector(&normal);
	return (normal);
}
