/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:51:22 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/24 10:36:22 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "v3d.h"

// rm later
# include "scene.h"

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
BOOL	file_handler(int argc, char **argv);

void	parser_struct_free(t_parser *f);
void	file_parser(int fd);

void	error_exit(char *error_msg, t_parser *f);
void	parser_finish_error_exit(char *error_msg, t_parser *f);

char	**minirt_split(char const *s);

void	parse_camera(t_parser *f);
void	parse_ambient_light(t_parser *f);
void	parse_light(t_parser *f);
void	parse_sphere(t_parser *f);
void	parse_cylinder(t_parser *f);
void	parse_plane(t_parser *f);

void	brightness_ratio_checkset(char *str, double *target_elems_data,
			t_parser *f);
void	color_checkset(char *str, int *target_elems_data, t_parser *f);
void	coordinate_checkset(char *str, t_v3d *target_elems_data,
			t_parser *f);
void	three_d_normalized_vector_checkset(char *str, t_v3d *target_elems_data,
			t_parser *f);
void	object_dimension_checkset(char *str, double *target_elems_data,
			t_parser *f);

void	str_array_free_everything(char **str_array);
int		free_str_array_and_return_code(char **str_array, int code);
int		check_char_amount_in_str(char *str, char c, int correct_amount);
int		ft_isinteger(char *s);
int		str_array_count_strings(char **str_array);

double	ft_atof_simple(const char *s);
BOOL	ft_isdouble_simple(const char *s);

BOOL	create_object_and_add_to_lst_end(t_list **lst);
void	check_color(char *str, t_parser *f);

#endif