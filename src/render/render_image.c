/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:23:50 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/10 09:23:54 by dpalmer          ###   ########.fr       */
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

static void	img_pix_put(t_img *img, t_v2d pixel, int color)
{
	char	*dst;

	dst = img->addr + (int)pixel.e[1] * img->line_length
		+ (int)pixel.e[0] * (img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
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

static u_int32_t	check_pixel(t_data *data, t_v2d pixel)
{
	t_ray		ray;
	// t_color	color;
	u_int32_t	color;

	// color = (t_color){0, 0, 0};
	color = BLACK_COLOR;
	ray = create_ray(&data->scene.cameras[0], pixel);
	if (hit_sphere(&data->scene.objects[0], &ray))
		color = RED_COLOR;
	return (color);
}

void	render_image(t_data *data)
{
	t_xy		pixel;
	t_camera	cam;
	int			color;

	ft_printf("start of render_image\n");
	cam = data->scene.cameras[0];
	init_camera(&cam);
	pixel = (t_xy){0, 0};
	while (pixel.e[1] < WINDOW_HEIGHT)
	{
		pixel.e[0] = 0;
		while (pixel.e[0] < WINDOW_WIDTH)
		{
			color = check_pixel(data, pixel);
			img_pix_put(&data->img, pixel, color);
			pixel.e[0]++;
		}
		pixel.e[1]++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	ft_printf("end of render_image\n");
}
