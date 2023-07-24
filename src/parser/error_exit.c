/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:36:54 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/24 10:45:59 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "scene.h"
#include "globals.h"

/*	this function is used if an error occurs during parsing.
	Will free everything malloced and exit with 1. */
static void	parser_error_exit(t_parser *f, t_scene *scene)
{
	scene_free_elems(scene);
	parser_struct_free(f);
	exit(1);
}

/*	This function is used to print the given error msg and
	after that exit the program.

	First prints out Error.
	Then prints out the specific error encountered.
	Then prints out the part where the error was encountered.
	Then prints out the line number and line where the error was encountered.
	Finally goes to error_exit function.
	*/
void	error_exit(char *error_msg, t_parser *f)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	if (f->error_part != NULL)
	{
		ft_putstr_fd("Error encountered here: ", 2);
		ft_putendl_fd(f->error_part, 2);
	}
	ft_putstr_fd("in line ", 2);
	ft_putnbr_fd(f->line_nbr, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(f->line, 2);
	parser_error_exit(f, &g_scene);
}

/*	This function is used if we find an error after finishing parsing
	(errors like no ambient light, no cameras, etc.)
	This is a separate function from error_exit because there isn't a
	specific part or line where there would be an error.*/
void	parser_finish_error_exit(char *error_msg, t_parser *f)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	parser_error_exit(f, &g_scene);
}
