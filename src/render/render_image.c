/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:23:50 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/10 14:17:26 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "scene.h"
#include "v3d.h"
#include "color.h"
#include "camera.h"

static void	img_pix_put(t_img *img, t_v2d pixel, int color)
{
	char	*dst;

	dst = img->addr + (int)pixel.e[1] * img->line_length
		+ (int)pixel.e[0] * (img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

static uint32_t	check_pixel(t_data *data, t_v2d pixel)
{
	t_ray		ray;
	t_color		color;
	t_camera	cam;
	t_scene		*scene;

	cam = data->scene.cameras[0];
	scene = &data->scene;
	color = (t_color){0, 0, 0};
	ray = create_ray(&cam, pixel);
	//TODO: update the color with the trace_ray func.
	//TODO: deal with overflow? Not sure exactly what Dorian was talking about
	return (color_to_int(color));
}

static t_color	trace_ray(t_ray *ray, t_scene *scene, uint32_t depth)
{
	/* TODO:
	find closest;
	get light color;
	shade pixel;
	check reflections;
	reshade;
	deal with overflow again?
	*/
}

void	render_image(t_data *data)
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
