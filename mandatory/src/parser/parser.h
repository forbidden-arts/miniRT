/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:10:14 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/29 13:46:17 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "v3d.h"
# include "scene.h"

# define AMBIENT_LIGHT_ID	"A"
# define CAMERA_ID			"C"
# define LIGHT_ID			"L"
# define SPHERE_ID			"sp"
# define CYLINDER_ID		"cy"
# define PLANE_ID			"pl"

typedef struct s_file_parser
{
	char	*line;
	int		fd;
	int		index_sphape;
	int		index_camera;
	int		index_light;
	BOOL	result;
	BOOL	ambient_light_found;
	BOOL	found_elem_match;
}	t_file_parser;

// parser_utils1.c
BOOL	return_err(
			char *error_msg,
			char *optional_str_to_free);
BOOL	free_str_and_return_false(
			char *str);
BOOL	ft_isinteger(
			char *s);
BOOL	color_part_checkset(
			char *color_data,
			double *target_data);
BOOL	check_char_amount_in_str(
			char *str,
			char c,
			int correct_amount);

// parser_utils2.c
BOOL	coordinate_part_checkset(
			char *str,
			double *target_data);
BOOL	axis_part_checkset(
			char *str,
			double *target_data);
BOOL	check_identifier(
			char *str,
			char *id);
void	print_error_line(
			char *line);
BOOL	free_str_array_and_return_false(
			char **str_array);

// parser_utils3.c
int		count_strings_in_array(
			char **str_array);
BOOL	check_if_empty_line(
			char *str);

// parser_checksets.c
BOOL	color_checkset(
			char *str,
			t_v3d *target_data);
BOOL	coordinate_checkset(
			char *str,
			t_v3d *target_data);
BOOL	axis_checkset(
			char *str,
			t_v3d *target_data);
BOOL	brightness_ratio_checkset(
			char *str,
			double *target_data);
BOOL	dimension_checkset(
			char *str,
			double *target_data,
			BOOL diameter);

// parser_double_utils.c
BOOL	ft_isdouble_simple(
			const char *s);

// parse_NAME.c
BOOL	parse_ambient(
			char *line,
			t_scene *scene);
BOOL	parse_camera(
			char *line,
			t_scene *scene,
			int index);
BOOL	parse_light(
			char *line,
			t_scene *scene,
			int index);
BOOL	parse_sphere(
			char *line,
			t_scene *scene,
			int index);
BOOL	parse_cylinder(
			char *line,
			t_scene *scene,
			int index);
BOOL	parse_plane(
			char *line,
			t_scene *scene,
			int index);

// parse_file_utils1.c
int		get_fd(
			char *argv);
BOOL	check_extension(
			char *argv);
BOOL	init_file_parser_struct(
			t_file_parser *file_parser,
			char *argv);
BOOL	find_shape_match(
			t_file_parser *p,
			t_scene *scene);
BOOL	find_non_shape_match(
			t_file_parser *p,
			t_scene *scene);

// parse_file_utils2.c
char	*free_str_and_set_as_null(
			char *str);

BOOL	minirt_start(
			int argc,
			char **argv,
			t_scene *scene);

double	ft_atod(
			char *str);

void	print_scene_data(
			t_scene *scene);

void	print_v3d_data(
			t_v3d *v3d);
void	print_object_data(
			t_scene *scene);

#endif