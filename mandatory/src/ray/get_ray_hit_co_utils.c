/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit_co_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:05:26 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/29 13:28:23 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "ray.h"
#include "shapes.h"
#include "camera.h"

/*
cylinder:
	where a=xD2+yD2, b=2xExD+2yEyD, and c=xE2+yE2-1.
cone:
	where a=xD2+yD2-zD2, b=2xExD+2yEyD-2zEzD, and c=xE2+yE2-zE2.
*/

BOOL	get_cone_quadratic(
	t_object *cone,
	t_ray *ray,
	double *t0,
	double *t1)
{
	// t_v3d	v3d_first;
	// t_v3d	v3d_second;
	t_v3d	cone_tip;
	t_v3d	quadratic_params;
	double	cone_angle;

	cone_angle = cos(atan(cone->radius / cone->height));
	cone_tip = get_shape_top(cone);
	cone_tip = v3d_subtract(&ray->origin, &cone_tip);
	quadratic_params.e[0] = v3d_dot(&ray->direction, &cone->axis)
		* v3d_dot(&ray->direction, &cone->axis) - cone_angle * cone_angle;
	quadratic_params.e[1] = 2.0 * (v3d_dot(&ray->direction, &cone->axis)
			* v3d_dot(&cone_tip, &cone->axis)
			- v3d_dot(&ray->direction, &cone_tip) * cone_angle * cone_angle);
	quadratic_params.e[2] = v3d_dot(&cone_tip, &cone->axis)
		* v3d_dot(&cone_tip, &cone->axis)
		- v3d_dot(&cone_tip, &cone_tip) * cone_angle * cone_angle;
	return (solve_quadratic(quadratic_params, t0, t1));
}

BOOL	ray_hit_cone_main_body(
	t_object *cone,
	t_ray *ray,
	double *impact_time)
{
	t_v2d	t_params;
	t_v3d	temp1;
	t_v3d	temp2;
	double	dist;

	if (!get_cone_quadratic(cone, ray, &t_params.e[0], &t_params.e[1]))
		return (FALSE);
	if (!get_closest_t(t_params.e[0], t_params.e[1], impact_time))
		return (FALSE);
	temp1 = v3d_multiply_scalar(&ray->direction, *impact_time);
	temp2 = v3d_subtract(&cone->point, &ray->origin);
	temp1 = v3d_subtract(&temp1, &temp2);
	dist = v3d_dot(&cone->axis, &temp1);
	if (!(dist >= -cone->height / 2 && dist <= cone->height / 2))
		return (FALSE);
	// tip_pos = get_shape_top(cone);
	// temp1 = ray_at(ray, *impact_time);
	// temp1 = v3d_subtract(&temp1, &tip_pos);
	// dist = v3d_dot(&temp1, &cone->axis);
	// if (dist < EPSILON || dist > cone->height)
	// 	return (FALSE);
	return (TRUE);
}

BOOL	ray_hit_cone_cap(
	t_object *cone,
	t_ray *ray,
	double *cap_time)
{
	t_object	cap;

	set_cap_values(cone, &cap, TRUE);
	return (ray_hit_cap(cap_time, &cap, ray));
}
