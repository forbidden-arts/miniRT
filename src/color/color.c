/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:41:19 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/14 10:57:48 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

uint32_t	color_to_int(t_color color)
{
	uint32_t	red;
	uint32_t	green;
	uint16_t	blue;

	red = 255.0 * color.e[0];
	green = 255.0 * color.e[1];
	blue = 255.0 * color.e[2];
	return ((red << 16) | (green << 8) | blue);
}

t_color	int_to_color(uint32_t color)
{
	t_color	result;

	result.e[0] = (color << 16) & 0xFF;
	result.e[1] = (color << 8) & 0xFF;
	result.e[2] = color & 0xFF;
	return (result);
}

void	normalize_rgb(t_color *color)
{
	color->e[0] /= 255.0;
	color->e[1] /= 255.0;
	color->e[2] /= 255.0;
}

void	color_overflow(t_color *color)
{
	double	over;

	over = 0.0;
	if (color->e[0] > 1)
		over += color->e[0] - 1;
	if (color->e[1] > 1)
		over += color->e[1] - 1;
	if (color->e[2] > 1)
		over += color->e[2] - 1;
	v3d_add_in_place(color, &(t_color){over, over, over});
	color->e[0] = fmin(color->e[0], 1);
	color->e[1] = fmin(color->e[1], 1);
	color->e[2] = fmin(color->e[2], 1);
}
