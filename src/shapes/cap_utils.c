/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:21:41 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/25 10:46:29 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_v3d	get_top_cap(
	t_object *object)
{
	t_v3d	displacement;

	displacement = v3d_multiply_scalar(&object->axis, object->height * 0.5);
	return (v3d_add(&object->point, &displacement));
}

t_v3d	get_bottom_cap(
	t_object *object)
{
	t_v3d	displacement;

	displacement = v3d_multiply_scalar(&object->axis, object->height * -0.5);
	return (v3d_add(&object->point, &displacement));
}

void	set_cap_values(
	t_object *object,
	t_object *cap,
	BOOL is_bottom)
{
	if (!is_bottom)
		cap->point = get_top_cap(object);
	else
		cap->point = get_bottom_cap(object);
	cap->radius = object->radius;
	cap->axis = object->axis;
}

BOOL	is_point_closer_to_top_cap(
	t_object *object,
	t_v3d *point,
	t_v3d *cap_center)
{
	t_v3d	top_cap_center;
	t_v3d	bottom_cap_center;

	top_cap_center = get_top_cap(object);
	bottom_cap_center = get_bottom_cap(object);
	if (v3d_get_dist(point, &top_cap_center)
		> v3d_get_dist(point, &bottom_cap_center))
	{
		*cap_center = top_cap_center;
		return (TRUE);
	}
	*cap_center = bottom_cap_center;
	return (FALSE);
}
