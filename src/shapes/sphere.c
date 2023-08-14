/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:56:47 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/14 07:23:22 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "v3d.h"

double	get_sphere_dist(const t_ray *ray, t_object *object)
{
	t_v3d	camera_dist;
	t_v3d	params;
	t_v2d	result;
	double	discriminant;
	double	divisor;

	camera_dist = v3d_subtract(&ray->origin, &object->point);
}

BOOL	hit_sphere(t_object *sphere, t_ray *ray)
{
	t_v3d	oc;
	double	a;
	double	b;
	double	c;
	double	d;

	oc = v3d_subtract(&ray->origin, &sphere->point);
	a = v3d_dot(&ray->direction, &ray->direction);
	b = 2.0 * v3d_dot(&oc, &ray->direction);
	c = v3d_dot(&oc, &oc) - sphere->radius * sphere->radius;
	d = (b * b) - (4 * a * c);
	return (d > 0);
}
