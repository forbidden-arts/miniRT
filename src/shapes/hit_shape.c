/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:29:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/02 16:22:54 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "v3d.h"

/*	just spitballing*/
int	get_pixel_color(t_ray *ray, t_scene *scene, double *hit_distance)
{
	t_object	*shape;
	t_v3d		color;

	v3d_init(&color);
}

static BOOL	hit_sphere(t_ray *ray, t_object *sphere, double *hit_distance)
{
	
}

static BOOL	hit_plane(t_ray *ray, t_object *plane, double *hit_distance)
{

}

static BOOL	hit_cylinder(t_ray *ray, t_object *cylinder, double *hit_distance)
{

}

BOOL	hit_shape(t_ray *ray, t_scene *scene)
{
	double	hit_distance;

	if ()
}
