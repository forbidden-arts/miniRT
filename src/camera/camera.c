/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:09:55 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/10 12:18:40 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "data.h"
#include "scene.h"
#include "v3d.h"
#include "camera.h"

#include <stdio.h>
#include "parser.h"

void	init_camera(t_camera *camera)
{
	printf("Init Camera\n");
	printf("\nCam-Loc\n");
	print_v3d_data(&camera->location);
	printf("\nCam-Dir\n");
	print_v3d_data(&camera->direction);
	camera->right = v3d_cross(&camera->direction, &(t_v3d){0.0, 1.0, UPSILON});
	camera->right = v3d_unit_vector(&camera->right);
	printf("\nCam->Right\n");
	print_v3d_data(&camera->right);
	camera->up = v3d_cross(&camera->right, &camera->direction);
	camera->up = v3d_unit_vector(&camera->up);
	printf("\nCam->Up\n");
	print_v3d_data(&camera->up);
	// camera->field_of_view = degrees_to_radians(camera->field_of_view);
	camera->aspect = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	printf("\nAspect: %f\n", camera->aspect);
}

t_ray	create_ray(t_camera *cam, const t_v2d pixel)
{
	double	x_norm;
	double	y_norm;
	double	fisheye[3];
	t_v3d	temp[3];
	t_ray	primary;

	printf("\nCreate Ray");
	printf("\nCam-Loc\n");
	print_v3d_data(&cam->location);
	printf("\nCam-Dir\n");
	print_v3d_data(&cam->direction);
	printf("\nCam->Right\n");
	print_v3d_data(&cam->right);
	printf("\nCam->Up\n");
	print_v3d_data(&cam->up);
	// printf("FOV_X: %f", ((double)cam->field_of_view * DEG2RAD));
	// printf("FOV_Y: %f", tan((double)cam->field_of_view * DEG2RAD));
	x_norm = (1.0 - (2.0 * (pixel.e[0] + 0.5) / WINDOW_WIDTH))
		* (WINDOW_WIDTH/WINDOW_HEIGHT) * tan((double)cam->field_of_view * DEG2RAD);
	y_norm = (1.0 - (2.0 * (pixel.e[1] + 0.5) / WINDOW_HEIGHT))
		* tan((double)cam->field_of_view * DEG2RAD);
	// printf("x_norm: %f, y_norm: %f\n", x_norm, y_norm);
	fisheye[2] = sqrt(x_norm * x_norm + y_norm * y_norm) / 2;
	fisheye[0] = fisheye[2] * cos(atan2(y_norm, x_norm));
	fisheye[1] = fisheye[2] * sin(atan2(y_norm, x_norm));
	printf("pixel (%f, %f) fish %f, %f, %f\n", pixel.e[0], pixel.e[1], fisheye[0], fisheye[1], fisheye[2]);
	temp[0] = v3d_multiply_scalar(&cam->right, fisheye[0]);
	// print_v3d_data(&temp[0]);
	temp[1] = v3d_multiply_scalar(&cam->up, fisheye[1]);
		// print_v3d_data(&cam->up);
		// print_v3d_data(&temp[1]);
	temp[2] = v3d_add(&temp[0], &temp[1]);
		// print_v3d_data(&temp[2]);
	primary.origin = cam->location;
	primary.direction = v3d_add(&cam->direction, &temp[2]);
		// print_v3d_data(&primary.direction);
	// printf("\n");
	primary.direction = v3d_unit_vector(&primary.direction);
	// print_v3d_data(&primary.direction);
	// printf("\n");
	exit(1);
	return (primary);
}
