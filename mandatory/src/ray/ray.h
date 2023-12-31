/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:48:32 by dpalmer           #+#    #+#             */
/*   Updated: 2023/09/04 17:22:56 by ssalmi           ###   ########.fr       */
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
void		populate_impact(
				t_scene *scene,
				const t_ray *ray,
				t_impact *impact);

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

t_light		check_light(
				t_scene *scene,
				t_impact *impact);
t_ray		reflect_ray(
				const t_ray *original,
				const t_impact *impact);

BOOL		ray_hit_cylinder_main_body(
				t_object *cylinder,
				t_ray *ray,
				double *impact_time);
BOOL		ray_hit_cylinder_caps(
				t_object *cylinder,
				t_ray *ray,
				double *cap_time);

t_v3d		get_object_normal(
				t_object *object,
				t_impact *impact);

BOOL		get_cylinder_quadratic(
				t_object *cylinder,
				t_ray *ray,
				double *t0,
				double *t1);

t_v3d		get_shape_top(
				t_object *object);
t_v3d		get_shape_bottom(
				t_object *object);
void		set_cap_values(
				t_object *object,
				t_object *cap,
				BOOL is_bottom);
BOOL		is_point_closer_to_top_cap(
				t_object *object,
				t_v3d *point,
				t_v3d *cap_center);

BOOL		is_inside_cylinder(
				t_v3d *point,
				t_object *cylinder);

#endif
