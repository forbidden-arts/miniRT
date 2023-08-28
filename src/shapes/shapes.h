/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:25:21 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/28 12:52:25 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "scene.h"
# include "ray.h"

t_v3d	get_object_normal(
			t_object *object,
			t_v3d *impact);

BOOL	get_cylinder_quadratic(
			t_object *cylinder,
			t_ray *ray,
			double *t0,
			double *t1);

t_v3d	get_shape_top(
			t_object *object);
t_v3d	get_shape_bottom(
			t_object *object);
void	set_cap_values(
			t_object *object,
			t_object *cap,
			BOOL is_bottom);
BOOL	is_point_closer_to_top_cap(
			t_object *object,
			t_v3d *point,
			t_v3d *cap_center);
#endif