/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit_shapes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:49:57 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/13 14:34:40 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

BOOL	get_ray_hit_sphere(t_impact *impact, t_object *sphere, t_ray *ray)
{
	t_v3d	quadratic_params;
	t_v3d	oc;
	t_v2d	t_params;
	double	closest_t;

	oc = v3d_subtract(&ray->origin, &sphere->point);
	quadratic_params.e[0] = v3d_dot(&ray->direction, &ray->direction);
	quadratic_params.e[1] = 2.0 * v3d_dot(&oc, &ray->direction);
	quadratic_params.e[2] = v3d_dot(&oc, &oc) - sphere->radius * sphere->radius;
	if (!solve_quadratic(quadratic_params, &t_params.e[0], &t_params.e[1]))
		return (FALSE);
	if (get_closest_t(t_params.e[0], t_params.e[1], &closest_t) == FALSE)
		return (FALSE);
	impact->object = sphere;
	impact->object_type = SPHERE;
	impact->point = get_impact_point(&ray->origin, &ray->direction, closest_t);
	impact->distance = calculate_impact_distance(&ray->origin, &impact->point);
	impact->normal = calculate_impact_normal_sphere(sphere, &impact->point);
	return (TRUE);
}

BOOL	get_ray_hit_plane(t_impact *impact, t_object *plane, t_ray *ray)
{
	(void)impact;
	(void)plane;
	(void)ray;
	return (FALSE);
}

BOOL	get_ray_hit_cylinder(t_impact *impact, t_object *cylinder,
			t_ray *ray)
{
	(void)impact;
	(void)cylinder;
	(void)ray;
	return (FALSE);
}
