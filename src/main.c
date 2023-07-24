/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:04:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/24 11:02:14 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Placeholder
#include "libft.h"
#include "parser.h"
#include "scene.h"
#include "globals.h"
#include <stdio.h>

t_scene	g_scene;

int	main(int argc, char **argv)
{
	BOOL	parser_result;

	scene_init(&g_scene);
	parser_result = file_handler(argc, argv);
	if (parser_result == TRUE)
		printf("parsing successful\n");
	return (0);
}
