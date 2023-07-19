/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:02:14 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/19 15:06:06 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "v3d.h"

typedef struct s_camera
{
	t_v3d	point;
	t_v3d	direction;
	int		field_of_view;
}	t_camera;

typedef struct s_scene
{
	t_list	*objects;
	t_list	*lights;
	t_list	*cameras;
	int		width;
	int		height;
	double	ambient_intensity;
	int		ambient_color;
	int		current_camera;
}	t_scene;

// 0, 1, 2, 3
typedef enum e_object
{
	SPHERE,
	CYLINDER,
	PLANE
}	t_object;

// funcs
int	scene_free_elems(t_scene *scene);

#endif
