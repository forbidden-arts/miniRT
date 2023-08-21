/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:52:45 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/21 12:34:52 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "ray.h"

void	ray_init(t_ray *ray)
{
	v3d_init(&(ray->origin));
	v3d_init(&(ray->direction));
}

void	ray_init_with_values(
	t_ray *ray,
	const t_point3 *origin,
	const t_v3d *direction)
{
	v3d_init_with_values(
		&(ray->origin),
		v3d_x(origin),
		v3d_y(origin),
		v3d_z(origin));
	v3d_init_with_values(
		&(ray->direction),
		v3d_x(direction),
		v3d_y(direction),
		v3d_z(direction));
}

t_point3	ray_at(const t_ray *ray, double t)
{
	t_v3d	scaled_dir;

	scaled_dir = v3d_multiply_scalar(&(ray->direction), t);
	return (v3d_add(&(ray->origin), &scaled_dir));
}

void	populate_impact(t_scene *scene, const t_ray *ray, t_impact *impact)
{
	t_v3d	temp;

	temp = v3d_multiply_scalar(&ray->direction, impact->time);
	impact->point = v3d_add(&ray->origin, &temp);
	temp = v3d_subtract(&ray->origin, &impact->point);
	impact->distance = v3d_length(&temp);
	impact->to_source = v3d_subtract(&impact->point, &ray->origin);
	v3d_unit_vector(&impact->to_source);
	impact->color = scene->objects[impact->index].color;
	impact->normal = get_object_normal(
			&scene->objects[impact->index], &impact->point);
}
