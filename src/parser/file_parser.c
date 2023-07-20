/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:57:51 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/20 15:51:08 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdio.h>

/*	this function free's everything malloced for file_parser_function_struct.
	If you change the parser-struct remember to add the values to free here.*/
void	parser_struct_free(t_file_parser_function *f)
{
	if (f->line)
		free(f->line);
	if (f->line_parts_array)
		free(f->line_parts_array);
}

static void	init_file_parser_func_struct(t_file_parser_function *f)
{
	printf("rm later; init_file_parser_func_struct\n");
	f->line = NULL;
	f->line_nbr = 0;
	f->elem_type = NULL;
	f->error = 0;
	f->ambient_light_bool = 0;
}

static int	find_matching_elem_type(t_file_parser_function *f)
{
	if (ft_strncmp(f->elem_type, AMBIENT_LIGHT, 2) == 0)
		return (parse_ambient_light(f));
	else if (ft_strncmp(f->elem_type, CAMERA, 2) == 0)
		return (parse_camera(f));
	else if (ft_strncmp(f->elem_type, LIGHT, 2) == 0)
		return (parse_light(f));
	else if (ft_strncmp(f->elem_type, SPHERE, 3) == 0)
		return (parse_sphere(f));
	else if (ft_strncmp(f->elem_type, CYLINDER, 3) == 0)
		return (parse_cylinder(f));
	else if (ft_strncmp(f->elem_type, PLANE, 3) == 0)
		return (parse_plane(f));
	else if (ft_strncmp(f->elem_type, "//", 2) == 0)
	{
		printf("rm later; hit a comment when parsing, skip line!\n");
		return (0);
	}
	else if (f->elem_type == NULL)
		return (0);
	else
	{
		f->error = 1;
		return (1);
	}
}

int	file_parser(int fd)
{
	t_file_parser_function	f;
	int						elem_parsing_result;

	init_file_parser_func_struct(&f);
	f.line = get_next_line(fd);
	while (f.line != NULL && !f.error)
	{
		f.elem_type = ft_strtok(f.line, DELIMITERS);
		elem_parsing_result = find_matching_elem_type(&f);
		if (elem_parsing_result != 0)
			parser_errors(&f);
		free(f.line);
		f.line = get_next_line(fd);
		f.line_nbr++;
	}
	return (0);
}
