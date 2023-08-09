/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:09:55 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/09 14:29:18 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "data.h"

// rm later:
#include "parser.h"
#include <stdio.h>

#include <math.h>

void	init_camera(t_camera *camera)
{
	// recenter_for_mlx(&camera->location);
	camera->right = v3d_cross(&camera->direction, &(t_v3d){0, 1, 0});
	camera->up = v3d_cross(&camera->right, &camera->direction);
	camera->right = v3d_unit_vector(&camera->right);
	camera->up = v3d_unit_vector(&camera->up);
	camera->field_of_view = degrees_to_radians(camera->field_of_view);
	// printf("INIT_CAMERA RESULTS:\n");
	// printf("camera right: ");
	// print_v3d_data(&camera->right);
	// printf("\ncamera up: ");
	// print_v3d_data(&camera->up);
	// printf("\n");
}