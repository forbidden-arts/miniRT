/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:02:09 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/20 11:31:40 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdio.h>

static int	parser_error_unknown_type(t_file_parser_function *f)
{
	printf("Unknown type: %s\n", f->elem_type);
	printf("(in line: %d)\n", f->line_nbr);
	return (0);
}

/*	This function is called if there is somekind of error when parsing
	the file. It will first print error, after which it will go to function
	that will print a more specific reason for the error.
	Finally it will free everything allocated (at this point the only things
	malloced are the file_parser_function-struct and the scene-struct) and
	exit the program.
	
	errors:
	1. unknown element type
	
	BEFORE EXIT FREE EVERYHTING MALLCODED!*/
int	parser_errors(t_file_parser_function *f)
{
	printf("Error\n");
	if (f->error == 1)
		parser_error_unknown_type(f);
	if (f->line != NULL)
		free(f->line);
	exit(f->error);
}
