/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:29:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/21 12:31:04 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"

static t_v3d	get_cylinder_normal(t_object *cylinder, t_v3d *impact)
{
	t_v3d	center_to_impact;
	t_v3d	projected_axis_point;
	t_v3d	projected_point;
	double	distance_along_axis;

	center_to_impact = v3d_subtract(impact, &cylinder->point);
	distance_along_axis = v3d_dot(&center_to_impact, &cylinder->axis);
	projected_axis_point = v3d_multiply_scalar(&cylinder->axis,
			distance_along_axis);
	projected_point = v3d_add(&cylinder->point, &projected_axis_point);
	return (v3d_subtract(impact, &projected_point));
}

t_v3d	get_object_normal(t_object *object, t_v3d *impact)
{
	t_v3d	normal;

	if (object->type == SPHERE)
		normal = v3d_subtract(impact, &object->point);
	if (object->type == CYLINDER)
		normal = get_cylinder_normal(object, impact);
	v3d_unit_vector(&normal);
	return (normal);
}
