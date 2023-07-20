/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:36:54 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/20 15:56:26 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "scene.h"

/*	this function is used if an error occurs during parsing.
	Will free everything malloced and exit with 1. */
void	error_exit(t_file_parser_function *f, t_scene *scene)
{
	scene_free_elems(scene);
	parser_struct_free(f);
	exit(1);
}
