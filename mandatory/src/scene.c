/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:26 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/22 15:01:28 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "data.h"
#include "v3d.h"

/*	Free everything malloced for scene	*/
void	free_scene(
	t_scene *scene)
{
	if (scene->objects)
		free(scene->objects);
	if (scene->lights)
		free(scene->lights);
	if (scene->cameras)
		free(scene->cameras);
}

/*	Function to initiate scene variables to NULL	*/
void	init_scene(
	t_scene *scene)
{
	scene->objects = NULL;
	scene->lights = NULL;
	scene->cameras = NULL;
	v3d_init(&scene->ambient.color);
	scene->ambient.intensity = 0;
	scene->width = WINDOW_WIDTH;
	scene->height = WINDOW_HEIGHT;
	scene->current_camera = 0;
	scene->n_lights = 0;
	scene->n_cameras = 0;
	scene->n_objects = 0;
}
