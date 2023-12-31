/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:23:50 by ssalmi            #+#    #+#             */
/*   Updated: 2023/09/04 15:29:12 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "scene.h"
#include "v3d.h"
#include "camera.h"
#include "color.h"
#include "ray.h"
#include "render.h"

static void	img_pix_put(
	t_img *img,
	t_v2d pixel,
	int color)
{
	char	*dst;

	dst = img->addr + (int)pixel.e[1] * img->line_length
		+ (int)pixel.e[0] * (img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

t_color	ray_trace(
	t_ray *ray,
	t_scene *scene,
	int depth)
{
	t_impact	impact;
	t_light		light;
	t_color		color;

	if (depth >= MAX_DEPTH)
		return ((t_color){0, 0, 0});
	if (!ray_hit(scene, &impact, ray))
		return ((t_color){0, 0, 0});
	populate_impact(scene, ray, &impact);
	light = check_light(scene, &impact);
	color = shade_hit(scene, &impact, &light);
	color_overflow(&color);
	return (color);
}

static u_int32_t	check_pixel(
	t_data *data,
	t_v2d pixel)
{
	t_ray		ray;
	t_color		color;
	t_camera	cam;
	t_scene		*scene;

	cam = data->scene.cameras[0];
	scene = &data->scene;
	ray = create_ray(&cam, pixel);
	color = ray_trace(&ray, scene, 0);
	color_overflow(&color);
	return (color_to_int(color));
}

void	render_image(
	t_data *data)
{
	t_xy		pixel;
	t_camera	*cam;
	int			color;

	ft_printf("start of render_image\n");
	cam = &data->scene.cameras[0];
	init_camera(cam);
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
