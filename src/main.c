/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:04:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/25 11:50:38 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Placeholder
#include "libft.h"
#include "parser.h"
#include "data.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;
	BOOL	parser_result;

	scene_init(&data.scene);
	parser_result = file_handler(argc, argv, &data.scene);
	if (parser_result == TRUE)
		printf("parsing successful\n");
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "miniRT");
	data.img.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img,
			&data.img.bits_per_pixel,
			&data.img.line_length, &data.img.endian);
	mlx_hook(data.win_ptr, 17, 0, &press_close, &data);
	mlx_key_hook(data.win_ptr, &get_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
