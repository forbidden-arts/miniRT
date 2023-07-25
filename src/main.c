/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:04:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/25 11:14:45 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Placeholder
#include "libft.h"
#include "parser.h"
#include "scene.h"
#include "mlx_data.h"
#include "globals.h"
#include <stdio.h>

t_mlx	g_data;

int	main(int argc, char **argv)
{
	BOOL	parser_result;

	scene_init(&g_data.scene);
	parser_result = file_handler(argc, argv);
	if (parser_result == TRUE)
		printf("parsing successful\n");
	g_data.mlx_ptr = mlx_init();
	g_data.win_ptr = mlx_new_window(g_data.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "miniRT");
	g_data.img.img = mlx_new_image(g_data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	g_data.img.addr = mlx_get_data_addr(g_data.img.img,
			&g_data.img.bits_per_pixel,
			&g_data.img.line_length, &g_data.img.endian);
	mlx_hook(g_data.win_ptr, 17, 0, &press_close, &g_data);
	mlx_key_hook(g_data.win_ptr, &get_key, &g_data);
	mlx_loop(g_data.mlx_ptr);
	return (0);
}
