/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:43:57 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/10 12:51:32 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "mlx.h"
# include "scene.h"

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1920
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1080
# endif

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_scene		scene;
}	t_data;

int		press_close(t_data *data);
int		get_key(int key_code, t_data *data);

void	init_data(t_data *data);
void	free_data(t_data *data);

void	exit_minirt(t_data *data, int exit_code);

void	recenter_for_mlx(t_v3d *location);

void	render_image(t_data *data);

double	degrees_to_radians(double value);

#endif
