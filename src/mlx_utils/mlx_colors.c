/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:11:08 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/01 13:35:37 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

u_int32_t	rgb_to_int(const t_color color)
{
	int	red;
	int	green;
	int	blue;

	red = (int)color.e[0];
	green = (int)color.e[1];
	blue = (int)color.e[2];
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

void	recenter_for_mlx(t_v3d *location)
{
	location->e[0] += (WINDOW_WIDTH / 2);
	location->e[1] += (WINDOW_HEIGHT / 2);
}
