/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:57:51 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/24 10:51:17 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "scene.h"
#include "globals.h"
#include <stdio.h>

/*	this function free's everything malloced for file_parser_function_struct.
	If you change the parser-struct remember to add the values to free here.*/
void	parser_struct_free(t_parser *f)
{
	if (f->line)
		free(f->line);
	if (f->line_parts_array)
		free(f->line_parts_array);
}

static void	init_file_parser_func_struct(t_parser *f)
{
	f->line = NULL;
	f->line_parts_array = NULL;
	f->element_parts_array = NULL;
	f->line_nbr = 1;
	f->error_part = NULL;
	f->ambient_light_bool = FALSE;
}

static void	find_matching_elem_type(t_parser *f)
{
	f->error_part = f->line_parts_array[0];
	if (f->line_parts_array[0] == NULL
		|| ft_strncmp(f->line_parts_array[0], "//", 2) == 0)
		return ;
	else if (ft_strncmp(f->line_parts_array[0], AMBIENT_LIGHT_ID, 2) == 0)
		parse_ambient_light(f);
	else if (ft_strncmp(f->line_parts_array[0], CAMERA_ID, 2) == 0)
		parse_camera(f);
	else if (ft_strncmp(f->line_parts_array[0], LIGHT_ID, 2) == 0)
		parse_light(f);
	else if (ft_strncmp(f->line_parts_array[0], SPHERE_ID, 3) == 0)
		parse_sphere(f);
	else if (ft_strncmp(f->line_parts_array[0], CYLINDER_ID, 3) == 0)
		parse_cylinder(f);
	else if (ft_strncmp(f->line_parts_array[0], PLANE_ID, 3) == 0)
		parse_plane(f);
	else
		error_exit("Unknown type given", f);
}

/*	This function is used after parsing the file, checks things like
	that there is an ambient_light or cameras. */
static	void	file_parser_finish_check(t_scene *scene, t_parser *f)
{
	if (f->ambient_light_bool == FALSE)
		parser_finish_error_exit("No ambient light element in file!", f);
	if (scene->cameras == NULL)
		parser_finish_error_exit("No camera element in file!", f);
	if (scene->objects == NULL)
		parser_finish_error_exit("No object element in file!", f);
}

/*	This is the function that reads through the given file and
	parsers the lines of the file and stores the data so that
	it can be used to create the scene to visualize later.
	
	Almost all of the functions used for the parsing are void
	functions. This can be done because the scene is a global variable.
	
	If an error is encountered during the parsing,
	an error message is printed that tells the user what was
	the error, where the error was encountered and finally the line number
	and line where this happened.
	
	After the all of the files lines are gone through, the parser checks that
	the required elements are present in the scene-data.
	
	If the program has not quit (no errors),
	it can continue to create the scene!*/
void	file_parser(int fd)
{
	t_parser	f;

	init_file_parser_func_struct(&f);
	f.line = get_next_line(fd);
	while (f.line != NULL)
	{
		f.line_parts_array = minirt_split(f.line);
		if (!f.line_parts_array)
			error_exit("split malloc failure", &f);
		find_matching_elem_type(&f);
		free(f.line);
		free(f.line_parts_array);
		f.line_parts_array = NULL;
		f.line = get_next_line(fd);
		f.line_nbr++;
	}
	file_parser_finish_check(&g_scene, &f);
}
