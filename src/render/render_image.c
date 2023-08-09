/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:23:50 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/09 16:48:07 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "scene.h"
#include "v3d.h"
#include "camera.h"

// rm later; used to get
#include <stdio.h>
// colors
#define BLACK_COLOR	0x000000
#define RED_COLOR	0xFF0000

// BOOL	solve_quadratic(t_v3d params)
// {
// 	double	discriminant;
// 	double	a;
// 	double	b;
// 	double	c;

// 	a = v3d_dot()
// 	discriminant = pow(params.e[1], 2) - 4 * params.e[0] * params.e[2];
// 	if (discriminant <= 0)
// 		return (FALSE);
// 	return (TRUE);
// }

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x > 0 && x < WINDOW_WIDTH && y > 0 && y < WINDOW_HEIGHT)
	{
		i = img->bits_per_pixel - 8;
		pixel = img->addr + (y * img->line_length + x
				* (img->bits_per_pixel / 8));
		while (i >= 0)
		{
			if (img->endian != 0)
				*pixel++ = (color >> i) & 0xFF;
			else
				*pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
			i -= 8;
		}
	}
}

BOOL	hit_sphere(t_object *sphere, t_ray *ray)
{
	t_v3d	oc;
	double	a;
	double	b;
	double	c;
	double	d;

	// printf("origin %f, %f, %f, point: %f, %f, %f\n", ray->origin.e[0], ray->origin.e[1], ray->origin.e[2], sphere->point.e[0], sphere->point.e[1], sphere->point.e[2]);
	oc = v3d_subtract(&ray->origin, &sphere->point);
	a = v3d_dot(&ray->direction, &ray->direction);
	b = 2.0 * v3d_dot(&oc, &ray->direction);
	c = v3d_dot(&oc, &oc) - sphere->radius * sphere->radius;
	d = (b * b) - (4 * a * c);
	return (d > 0);
}

void	get_ray_direction(t_camera *cam, t_xy *theta, t_v3d *direction)
{
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;

	direction->e[0] = cam->direction.e[0] + cam->right.e[0]
		* tan(theta->e[0]) * aspect_ratio + cam->up.e[0] * tan(theta->e[1]);
	direction->e[1] = cam->direction.e[1] + cam->right.e[1]
		* tan(theta->e[0]) * aspect_ratio + cam->up.e[1] * tan(theta->e[1]);
	direction->e[2] = cam->direction.e[2] + cam->right.e[2]
		* tan(theta->e[0]) * aspect_ratio + cam->up.e[2] * tan(theta->e[1]);
	*direction = v3d_unit_vector(direction);
}

double	degrees_to_radians(double value)
{
	return (value * M_PI / 180);
}

// /*	this is just for testing. render the image from */
// void	render_image(t_data *data)
// {
// 	t_xy		pixel;
// 	t_camera	cam;
// 	t_ray		ray;


// 	cam = data->scene.cameras[0];
// 	init_camera(&cam);
// 	pixel = (t_xy){0, 0};
// 	while (pixel.e[1] < WINDOW_HEIGHT)
// 	{
// 		pixel.e[0] = 0;
// 		while (pixel.e[0] < WINDOW_WIDTH)
// 		{
// 			if (hit_sphere(&data->scene.objects[0], &ray))
// 			{
// 				printf("hit! %f, %f\n", pixel.e[0], pixel.e[1]);
// 				img_pix_put(&data->img, (int)pixel.e[0], (int)pixel.e[1], RED_COLOR);
// 			}
// 			pixel.e[0]++;
// 		}
// 		pixel.e[1]++;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
// 	ft_printf("end of render_image\n");
// }


/*	this is just for testing. render the image from */
void	render_image(t_data *data)
{
	t_xy		pixel;
	t_xy		theta_xy;
	t_camera	cam;
	t_ray		ray;

	ft_printf("start of render_image\n");
	cam = data->scene.cameras[0];
	init_camera(&cam);
	pixel = (t_xy){0, 0};
	while (pixel.e[1] < WINDOW_HEIGHT)
	{
		pixel.e[0] = 0;
		while (pixel.e[0] < WINDOW_WIDTH)
		{
			theta_xy.e[0] = (2 * pixel.e[0]) / WINDOW_WIDTH - 1;
			theta_xy.e[1] = 1 - (2 * pixel.e[1] / WINDOW_HEIGHT);
			get_ray_direction(&cam, &theta_xy, &ray.direction);
			ray.origin = cam.location;
			// printf("x: %f, y: %f\n", pixel.e[0], pixel.e[1]);
			if (hit_sphere(&data->scene.objects[0], &ray))
			{
				// printf("hit! %f, %f\n", pixel.e[0], pixel.e[1]);
				img_pix_put(&data->img, (int)pixel.e[0], (int)pixel.e[1], RED_COLOR);
			}
			pixel.e[0]++;
		}
		pixel.e[1]++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	ft_printf("end of render_image\n");
}
