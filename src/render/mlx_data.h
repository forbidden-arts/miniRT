/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:43:57 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 11:12:26 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DATA_H
# define MLX_DATA_H

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

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_scene		scene;
}	t_mlx;

int	press_close(t_mlx *data);
int	get_key(int key_code, t_mlx *data);

#endif