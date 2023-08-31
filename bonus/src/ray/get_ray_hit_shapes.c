/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_shapes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:49:57 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/16 14:25:25 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3d.h"
#include "render.h"

BOOL	ray_hit_sphere(
	t_impact *impact,
	t_object *sphere,
	t_ray *ray)
{
	t_v3d	quadratic_params;
	t_v3d	oc;
	t_v2d	t_params;

	oc = v3d_subtract(&ray->origin, &sphere->point);
	quadratic_params.e[0] = v3d_dot(&ray->direction, &ray->direction);
	quadratic_params.e[1] = 2.0 * v3d_dot(&oc, &ray->direction);
	quadratic_params.e[2] = v3d_dot(&oc, &oc) - sphere->radius * sphere->radius;
	if (!solve_quadratic(quadratic_params, &t_params.e[0], &t_params.e[1]))
		return (FALSE);
	if (!get_closest_t(t_params.e[0], t_params.e[1], &impact->time))
		return (FALSE);
	return (TRUE);
}

BOOL	ray_hit_plane(
	t_impact *impact,
	t_object *plane,
	t_ray *ray)
{
	double	denom;
	t_v3d	oc;
	double	t;

	denom = v3d_dot(&plane->axis, &ray->direction);
	if (fabs(denom) < EPSILON)
		return (FALSE);
	oc = v3d_subtract(&plane->point, &ray->origin);
	t = v3d_dot(&oc, &plane->axis) / denom;
	if (t < EPSILON)
		return (FALSE);
	impact->time = t;
	return (TRUE);
}

BOOL	ray_hit_cap(
	double *impact_time,
	t_object *cap,
	t_ray *ray)
{
	t_impact	impact;
	t_v3d		impact_point;

	if (!ray_hit_plane(&impact, cap, ray))
		return (FALSE);
	impact_point = ray_at(ray, impact.time);
	if (v3d_get_dist(&impact_point, &cap->point) > cap->radius)
		return (FALSE);
	*impact_time = impact.time;
	return (TRUE);
}

BOOL	ray_hit_cylinder(
	t_impact *impact,
	t_object *cylinder,
	t_ray *ray)
{
	BOOL	body_hit;
	BOOL	cap_hit;
	double	body_time;
	double	cap_time;

	body_hit = ray_hit_cylinder_main_body(cylinder, ray, &body_time);
	cap_hit = ray_hit_cylinder_caps(cylinder, ray, &cap_time);
	if (!body_hit && !cap_hit)
		return (FALSE);
	if (body_hit && cap_hit)
	{
		if (body_time < cap_time)
			impact->time = body_time;
		else
			impact->time = cap_time;
	}
	else if (body_hit)
		impact->time = body_time;
	else if (cap_hit)
		impact->time = cap_time;
	return (TRUE);
}

BOOL	ray_hit_cone(
	t_impact *impact,
	t_object *cone,
	t_ray *ray)
{
	BOOL	body_hit;
	BOOL	cap_hit;
	double	body_time;
	double	cap_time;

	body_hit = ray_hit_cone_main_body(cone, ray, &body_time);
	cap_hit = ray_hit_cone_cap(cone, ray, &cap_time);
	if (!body_hit && !cap_hit)
		return (FALSE);
	if (body_hit && cap_hit)
	{
		if (body_time < cap_time)
			impact->time = body_time;
		else
			impact->time = cap_time;
	}
	else if (body_hit)
		impact->time = body_time;
	else if (cap_hit)
		impact->time = cap_time;
	return (TRUE);
}
