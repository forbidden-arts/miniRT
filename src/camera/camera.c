/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:09:55 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/10 12:44:10 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "data.h"
#include "scene.h"
#include "v3d.h"
#include "camera.h"

void	init_camera(t_camera *camera)
{
	camera->right = v3d_cross(&camera->direction, &(t_v3d){0.0, 1.0, UPSILON});
	camera->right = v3d_unit_vector(&camera->right);
	camera->up = v3d_cross(&camera->right, &camera->direction);
	camera->up = v3d_unit_vector(&camera->up);
	camera->aspect = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
}

t_ray	create_ray(t_camera *cam, const t_v2d pixel)
{
	double	x_norm;
	double	y_norm;
	double	fisheye[3];
	t_v3d	temp[3];
	t_ray	primary;

	x_norm = (1.0 - (2.0 * (pixel.e[0] + 0.5) / WINDOW_WIDTH))
		* (cam->aspect) * tan((double)cam->field_of_view * DEG2RAD);
	y_norm = (1.0 - (2.0 * (pixel.e[1] + 0.5) / WINDOW_HEIGHT))
		* tan((double)cam->field_of_view * DEG2RAD);
	fisheye[2] = sqrt(x_norm * x_norm + y_norm * y_norm) / 2;
	fisheye[0] = fisheye[2] * cos(atan2(y_norm, x_norm));
	fisheye[1] = fisheye[2] * sin(atan2(y_norm, x_norm));
	temp[0] = v3d_multiply_scalar(&cam->right, fisheye[0]);
	temp[1] = v3d_multiply_scalar(&cam->up, fisheye[1]);
	temp[2] = v3d_add(&temp[0], &temp[1]);
	primary.origin = cam->location;
	primary.direction = v3d_add(&cam->direction, &temp[2]);
	primary.direction = v3d_unit_vector(&primary.direction);
	return (primary);
}
