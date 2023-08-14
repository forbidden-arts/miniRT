/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:12:26 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/14 13:53:25 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "v3d.h"
#include "render.h"
#include "scene.h"

#define AMB 0
#define DIF 1
#define RES 2

t_color	shade_hit(const t_scene *scene, const t_impact *impact)
{
	t_color	color[3];
	size_t	index;

	index = 0;
	ft_bzero(color, 3 * sizeof(t_v3d));
	color[AMB] = v3d_multiply_scalar(&scene->ambient.color,
			scene->ambient.intensity);
	color[AMB] = v3d_multiply(&impact->object->color, &color[AMB]);
	while (index < scene->n_lights)
	{
		if (CHECK_LIGHT_VS_IMPACT)
			color[DIF] = v3d_multiply(&impact->object->color,
					&scene->lights[index].color);
		color[RES] = v3d_add(&color[RES], &color[DIF]);
		index++;
	}
	color[RES] = v3d_multiply_scalar(&color[RES],
			(double)scene->lights[index].intensity / 100);
	color[RES] = v3d_add(&color[AMB], &color[RES]);
	return (color[RES]);
}
