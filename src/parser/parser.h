/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:51:22 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 13:21:37 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "v3d.h"
# include "scene.h"
# include "object.h"

# define AMBIENT_LIGHT_ID	"A"
# define CAMERA_ID		 	"C"
# define LIGHT_ID			"L"
# define SPHERE_ID		 	"sp"
# define CYLINDER_ID	 	"cy"
# define PLANE_ID		 	"pl"

typedef struct s_parser
{
	char	*line;
	char	**line_parts_array;
	char	**element_parts_array;
	int		line_nbr;
	BOOL	ambient_light_bool;
	char	*error_part;
}	t_parser;

// functions
BOOL	file_handler(int argc, char **argv, t_scene *scene);

void	parser_struct_free(t_parser *f);
void	file_parser(int fd, t_scene *scene);

void	error_exit(char *error_msg, t_parser *f, t_scene *scene);
void	parser_finish_error_exit(char *error_msg, t_parser *f, t_scene *scene);

char	**minirt_split(char const *s);

void	parse_camera(t_parser *f, t_scene *scene);
void	parse_ambient_light(t_parser *f, t_scene *scene);
void	parse_light(t_parser *f, t_scene *scene);
void	parse_sphere(t_parser *f, t_scene *scene);
void	parse_cylinder(t_parser *f, t_scene *scene);
void	parse_plane(t_parser *f, t_scene *scene);

void	brightness_ratio_checkset(char *str, double *target_elems_data,
			t_parser *f, t_scene *s);
void	color_checkset(char *str, int *target_elems_data, t_parser *f,
			t_scene *s);
void	coordinate_checkset(char *str, t_v3d *target_elems_data,
			t_parser *f, t_scene *s);
void	three_d_normalized_vector_checkset(char *str, t_v3d *target_elems_data,
			t_parser *f, t_scene *s);
void	object_dimension_checkset(char *str, double *target_elems_data,
			t_parser *f, t_scene *s);

void	str_array_free_everything(char **str_array);
int		free_str_array_and_return_code(char **str_array, int code);
int		check_char_amount_in_str(char *str, char c, int correct_amount);
int		ft_isinteger(char *s);
int		str_array_count_strings(char **str_array);

double	ft_atof_simple(const char *s);
BOOL	ft_isdouble_simple(const char *s);

BOOL	create_object_and_add_to_lst_end(t_list **lst);
void	check_color(char *str, t_parser *f, t_scene *scene);

// THESE ARE FOR TESTING, RM LATER
void	print_v3d_data(t_v3d *v3d);
void	print_parser_results(t_scene *scene);

void	print_sphere_data(t_object *sphere);
void	print_cylinder_data(t_object *cylinder);
void	print_plane_data(t_object *plane);

#endif