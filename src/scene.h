/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:02:14 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/18 15:11:32 by dpalmer          ###   ########.fr       */
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

#endif
