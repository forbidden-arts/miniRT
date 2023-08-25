/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:48:32 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/25 11:30:04 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "scene.h"
# include "v3d.h"

typedef struct s_ray
{
	t_point3	origin;
	t_v3d		direction;
}	t_ray;

/* Point is where on an object the ray impacts in a 3D space.
*  Normal the direction relative to the "center" of the object. */
typedef struct s_impact
{
	int			index;
	double		distance;
	double		time;
	t_color		color;
	t_v3d		point;
	t_v3d		normal;
	t_v3d		to_source;
	BOOL		hit_cap;
}	t_impact;

void		ray_init(
				t_ray *ray);
void		ray_init_with_values(
				t_ray *ray,
				const t_point3 *origin,
				const t_v3d *direction);
t_point3	ray_at(
				const t_ray *ray,
				double t);

BOOL		ray_hit(
				t_scene *scene,
				t_impact *impact,
				t_ray *ray);
BOOL		ray_hit_shapes(
				t_impact *temp,
				t_object *object,
				t_ray *ray);
BOOL		ray_hit_sphere(
				t_impact *impact,
				t_object *sphere,
				t_ray *ray);
BOOL		ray_hit_plane(
				t_impact *impact,
				t_object *plane,
				t_ray *ray);
BOOL		ray_hit_cap(
				double *impact_time,
				t_object *cap,
				t_ray *ray);
BOOL		ray_hit_cylinder(
				t_impact *impact,
				t_object *cylinder,
				t_ray *ray);

BOOL		get_closest_t(
				double t0,
				double t1,
				double *impact_time);
double		get_impact_distance(
				t_v3d *ray_origin,
				t_v3d *ray_impact_point);
t_v3d		get_impact_point(
				t_v3d *ray_origin,
				t_v3d *ray_direction,
				double t_parameter);
t_v3d		get_impact_normal(
				t_object *object,
				t_v3d *impact);
void		populate_impact(
				t_scene *scene,
				const t_ray *ray,
				t_impact *impact);
void		check_light(
				t_scene *scene,
				t_impact *impact);

BOOL		ray_hit_cylinder_main_body(
				t_object *cylinder,
				t_ray *ray,
				double *impact_time);
BOOL		ray_hit_cylinder_caps(
				t_object *cylinder,
				t_ray *ray,
				double *cap_time);

#endif
