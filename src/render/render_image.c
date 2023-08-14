/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:23:50 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/14 15:53:40 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "scene.h"
#include "v3d.h"
#include "camera.h"
#include "color.h"
#include "render.h"

// rm later; used to get
#include <stdio.h>
#include "parser.h"
// colors
#define BLACK_COLOR	0x000000
#define RED_COLOR	0xFF0000
#define BLUE_COLOR	0x0000FF
#define GREEN_COLOR	0x00FF00

static void	img_pix_put(t_img *img, t_v2d pixel, int color)
{
	char	*dst;

	dst = img->addr + (int)pixel.e[1] * img->line_length
		+ (int)pixel.e[0] * (img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

// BOOL	hit_sphere(t_object *sphere, t_ray *ray)
// {
// 	t_v3d	oc;
// 	double	a;
// 	double	b;
// 	double	c;
// 	double	d;

// 	oc = v3d_subtract(&ray->origin, &sphere->point);
// 	a = v3d_dot(&ray->direction, &ray->direction);
// 	b = 2.0 * v3d_dot(&oc, &ray->direction);
// 	c = v3d_dot(&oc, &oc) - sphere->radius * sphere->radius;
// 	d = (b * b) - (4 * a * c);
// 	return (d > 0);
// }

	// get closest hit
	// impact.object = NULL;
	// if (get_ray_hit(scene, &impact, &ray))
	// {
	// 	if (impact.object->color.e[0] == 255)
	// 		color = RED_COLOR;
	// 	else if (impact.object->color.e[1] == 255)
	// 		color = GREEN_COLOR;
	// 	else if (impact.object->color.e[2] == 255)
	// 		color = BLUE_COLOR;
	// }
	// else
	// 	color = BLACK_COLOR;

t_color	ray_trace(t_ray *ray, t_scene *scene, int depth)
{
	t_impact	impact;
	t_color		color;
	t_ray		reflected;
	t_color		reflected_color;
	// somethign ffor lights

	if (depth >= MAX_DEPTH)
		return ((t_color){0, 0, 0});
	if (!get_ray_hit(scene, &impact, ray))
		return ((t_color){0, 0, 0});
	//something for lights
	color = shade_hit(scene, &impact);
	return (color);
}

static u_int32_t	check_pixel(t_data *data, t_v2d pixel)
{
	t_ray		ray;
	t_color		color;
	t_camera	cam;
	t_scene		*scene;
	t_impact	impact;

	cam = data->scene.cameras[0];
	scene = &data->scene;
	ray = create_ray(&cam, pixel);
	color = ray_trace(&ray, scene, 0);
	color_overflow(&color);
	return (color_to_int(color));
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
