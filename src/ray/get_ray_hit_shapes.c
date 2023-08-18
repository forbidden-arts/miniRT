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

#include <stdio.h> //DELETE ME
#include "parser.h" //DELETE ME

BOOL	ray_hit_sphere(t_impact *impact, t_object *sphere, t_ray *ray)
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
	if (!get_closest_t(t_params.e[0], t_params.e[1], impact))
		return (FALSE);
	printf("\nImpact distance: %f\n", impact->distance);
	printf("Ray origin:\n");
	print_v3d_data(&ray->origin);
	printf("\nRay direction:\n");
	print_v3d_data(&ray->direction);
	return (TRUE);
}

BOOL	ray_hit_plane(t_impact *impact, t_object *plane, t_ray *ray)
{
	(void)impact;
	(void)plane;
	(void)ray;
	return (FALSE);
}

BOOL	ray_hit_cylinder(t_impact *impact, t_object *cylinder,
			t_ray *ray)
{
	(void)impact;
	(void)cylinder;
	(void)ray;
	return (FALSE);
}
