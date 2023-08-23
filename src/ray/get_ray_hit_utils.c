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
#include "shapes.h"

// rm later
#include <stdio.h>

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

BOOL	get_cylinder_quadratic(
	t_object *cylinder,
	t_ray *ray,
	double *t0,
	double *t1)
{
	t_v3d	v3d_first;
	t_v3d	v3d_second;
	t_v3d	v3d_temp;
	t_v3d	quadratic_params;

	v3d_first = v3d_multiply_scalar(&cylinder->axis,
			v3d_dot(&ray->direction, &cylinder->axis));
	v3d_first = v3d_subtract(&ray->direction, &v3d_first);
	v3d_temp = v3d_subtract(&ray->origin, &cylinder->point);
	v3d_second = v3d_multiply_scalar(&cylinder->axis,
			v3d_dot(&v3d_temp, &cylinder->axis));
	v3d_temp = v3d_subtract(&ray->origin, &cylinder->point);
	v3d_second = v3d_subtract(&v3d_temp, &v3d_second);
	quadratic_params.e[0] = v3d_dot(&v3d_first, &v3d_first);
	quadratic_params.e[1] = 2.0 * v3d_dot(&v3d_first, &v3d_second);
	quadratic_params.e[2] = v3d_dot(&v3d_second, &v3d_second)
		- cylinder->radius * cylinder->radius;
	if (!solve_quadratic(quadratic_params, t0, t1))
		return (FALSE);
	return (TRUE);
}

// check that impact time is correct!
BOOL	ray_hit_cylinder_main_body(
	t_object *cylinder,
	t_ray *ray,
	double *impact_time)
{
	t_v2d	t_params;
	t_v3d	temp1;
	t_v3d	temp2;
	double	dist;

	if (!get_cylinder_quadratic(cylinder, ray, &t_params.e[0], &t_params.e[1]))
		return (FALSE);
	if (!get_closest_t(t_params.e[0], t_params.e[1], impact_time))
		return (FALSE);
	temp1 = v3d_multiply_scalar(&ray->direction, *impact_time);
	temp2 = v3d_subtract(&cylinder->point, &ray->origin);
	temp1 = v3d_subtract(&temp1, &temp2);
	dist = v3d_dot(&cylinder->axis, &temp1);
	if (!(dist >= -cylinder->height / 2 && dist <= cylinder->height / 2))
		return (FALSE);
	return (TRUE);
}

BOOL	ray_hit_cylinder_caps(
	t_object *cylinder,
	t_ray *ray,
	double *cap_time)
{
	t_object	cap;
	double		top_time;
	double		bottom_time;
	BOOL		top_cap_hit;
	BOOL		bottom_cap_hit;

	set_cap_values(cylinder, &cap, FALSE);
	top_cap_hit = ray_hit_cap(&top_time, &cap, ray);
	set_cap_values(cylinder, &cap, TRUE);
	bottom_cap_hit = ray_hit_cap(&bottom_time, &cap, ray);
	if (!top_cap_hit && !bottom_cap_hit)
		return (FALSE);
	if (top_cap_hit && bottom_cap_hit)
	{
		if (bottom_time < top_time)
			*cap_time = bottom_time;
		else
			*cap_time = top_time;
	}
	else if (top_cap_hit)
		*cap_time = top_time;
	else if (bottom_cap_hit)
		*cap_time = bottom_time;
	return (TRUE);
}
