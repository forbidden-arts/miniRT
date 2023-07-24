/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:26 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/21 16:05:30 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"

void	scene_init(t_scene *scene)
{
	scene->ambient_color = -1;
	scene->ambient_intensity = -1;
	scene->cameras = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
	scene->current_camera = -1;
	scene->height = -1;
	scene->width = -1;
}

/*	This function simply frees everything allocated for the scene. Used
	if there is a parsing error while reading the file or when closing the
	program. */
void	scene_free_elems(t_scene *scene)
{
	ft_lstclear(&scene->objects, free);
	ft_lstclear(&scene->lights, free);
	ft_lstclear(&scene->cameras, free);
}
