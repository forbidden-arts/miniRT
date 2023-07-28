/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:02:14 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/28 13:14:10 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "v3d.h"

# define SPHERE	0;
# define CYLINDER 1;
# define PLANE 2;

typedef struct s_object
{
	int		type;
	t_v3d	point;
	t_v3d	normalized;
	t_v3d	axis;
	t_v3d	color;
	double	radius;
	double	height;
	double	width;
}	t_object;

typedef struct s_camera
{
	t_v3d	location;
	t_v3d	direction;
	int		field_of_view;
}	t_camera;

typedef struct s_light
{
	t_v3d	location;
	t_v3d	color;
	int		intensity;
}	t_light;

typedef struct s_ambient
{
	t_v3d	color;
	double	intensity;
}	t_ambient;


typedef struct s_scene
{
	t_object	*objects;
	t_light		*lights;
	t_camera	*cameras;
	t_ambient	ambient;
	int			width;
	int			height;
	int			current_camera;
	int			n_lights;
	int			n_cameras;
	int			n_objects;
}	t_scene;

typedef struct s_ray
{
	t_v3d	origin;
	t_v3d	direction;
}	t_ray;

// funcs
void	init_scene(t_scene *scene);
void	free_scene(t_scene *scene);

#endif
