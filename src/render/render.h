/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:50:53 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/11 11:48:12 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "data.h"
# include "scene.h"
# include "v3d.h"

typedef struct s_impact
{
	int			object_type;
	t_v3d		color;
	t_object	*object;
	double		distance;
	t_v3d		point;
	t_v3d		normal;
}	t_impact;

void	render_image(t_data *data);

BOOL	get_ray_hit(t_scene *scene, t_impact *impact, t_ray *ray);

BOOL	get_ray_hit_sphere(t_impact *impact, t_object *sphere, t_ray *ray);
BOOL	get_ray_hit_plane(t_impact *impact, t_object *plane, t_ray *ray);
BOOL	get_ray_hit_cylinder(t_impact *impact, t_object *cylinder,
			t_ray *ray);

BOOL	get_closest_t(double t0, double t1, double *closest_t);
double	calculate_impact_distance(t_v3d *ray_origin, t_v3d *ray_impact_point);
t_v3d	get_impact_point(t_v3d *ray_origin, t_v3d *ray_direction,
			double t_parameter);
t_v3d	calculate_impact_normal_sphere(t_object *sphere,
			t_v3d *impact_point);

#endif