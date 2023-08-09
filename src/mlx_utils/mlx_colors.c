/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:11:08 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/03 11:17:50 by ssalmi           ###   ########.fr       */
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
	location->e[0] += floor((WINDOW_WIDTH - 1) / 2.0);
	location->e[1] += floor((WINDOW_HEIGHT - 1) / 2.0);
}