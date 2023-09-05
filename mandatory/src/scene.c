/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:26 by ssalmi            #+#    #+#             */
/*   Updated: 2023/09/05 11:11:36 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"
#include "data.h"
#include "v3d.h"

void	free_scene(
	t_scene *scene)
{
	if (scene->objects)
		free(scene->objects);
	scene->objects = NULL;
	if (scene->lights)
		free(scene->lights);
	scene->lights = NULL;
	if (scene->cameras)
		free(scene->cameras);
	scene->cameras = NULL;
}

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
