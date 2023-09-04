/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit_co_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:05:26 by ssalmi            #+#    #+#             */
/*   Updated: 2023/09/04 14:26:01 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "ray.h"
#include "camera.h"

/*
cone:
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
