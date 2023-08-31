/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_ray_hit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:48:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/31 14:38:06 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	translate_normal(
	t_scene *scene,
	t_ray *shadow,
	t_impact *impact)
{
	if ((v3d_dot(&scene->cameras[0].direction, &impact->normal) < 0 && v3d_dot(&shadow->direction, &impact->normal) > 0) || (v3d_dot(&scene->cameras[0].direction, &impact->normal) > 0 && v3d_dot(&shadow->direction, &impact->normal) < 0))
	{
		impact->normal = v3d_multiply_scalar(&impact->normal, -1);
	}
}

static void	specular(
	t_scene	*scene,
	t_impact *impact,
	t_light *light,
	t_ray *shadow)
{
	t_v3d	half;
	t_v3d	temp;
	double	angle;
	double	specular;

	half = v3d_add(&scene->cameras->direction, &shadow->direction);
	half = v3d_unit_vector(&half);
	angle = fmax(v3d_dot(&impact->normal, &half), 0);
	specular = pow(angle, 60);
	temp = v3d_multiply_scalar(&light->color, specular * 1.5);
	light->color = v3d_add(&light->color, &temp);
}

static void	color_light(
	t_light *original,
	t_impact *impact,
	t_light *light,
	t_ray *shadow)
{
	t_color	color;

	light->intensity += fmax(v3d_dot(&impact->normal, &shadow->direction) \
		* original->intensity, 0);
	color = v3d_multiply_scalar(&original->color, light->intensity);
	v3d_add_in_place(&light->color, &color);
}

t_light	check_light(
	t_scene *scene,
	t_impact *impact)
{
	t_impact	temp_impact;
	t_light		light;
	t_ray		shadow;
	t_v3d		temp;
	int			index;

	index = 0;
	ft_bzero(&light, sizeof(t_light));
	while (index < scene->n_lights)
	{
		shadow.origin = scene->lights[index].location;
		temp = v3d_subtract(&impact->point, &shadow.origin);
		shadow.direction = v3d_unit_vector(&temp);
		if (ray_hit(scene, &temp_impact, &shadow) \
			&& fabs(v3d_get_dist(&shadow.origin, &impact->point) \
			- temp_impact.time) <= EPSILON)
		{
			translate_normal(scene, &shadow, impact);
			color_light(&scene->lights[index], impact, &light, &shadow);
			specular(scene, impact, &light, &shadow);
		}
		index++;
	}
	return (light);
}
