/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:38:22 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/22 13:22:41 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "scene.h"
# include "ray.h"
# include "v3d.h"

// Math funcs for int <> r,g,b & dealing with color "overflow"
t_color		int_to_color(uint32_t color);
uint32_t	color_to_int(t_color color);
void		normalize_rgb(t_color *color);
void		color_overflow(t_color *color);

// Calculating colors
t_color		shade_hit(
				t_scene *scene,
				t_impact *impact);

#endif
