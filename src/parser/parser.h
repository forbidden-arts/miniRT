/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:51:22 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/20 16:57:32 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define AMBIENT_LIGHT	"A"
# define CAMERA		 	"C"
# define LIGHT			"L"
# define SPHERE		 	"sp"
# define CYLINDER	 	"cy"
# define PLANE		 	"pl"

typedef struct s_file_parser_function
{
	char	*line;
	int		line_nbr;
	char	*elem_type;
	int		ambient_light_bool;
	int		error;
}	t_file_parser_function;

// functions
int		file_handler(int argc, char **argv);

int		file_parser(int fd);

char	**minirt_split(char const *s);

int		parse_camera(t_file_parser_function *f);
int		parse_ambient_light(t_file_parser_function *f);
int		parse_light(t_file_parser_function *f);
int		parse_sphere(t_file_parser_function *f);
int		parse_cylinder(t_file_parser_function *f);
int		parse_plane(t_file_parser_function *f);

int		parser_errors(t_file_parser_function *f);

void	str_array_free_everything(char **str_array);
int		free_str_array_and_return_code(char **str_array, int code);
int		check_char_amount_in_str(char *str, char c, int correct_amount);

double	ft_atof_simple(const char *s);
BOOL	ft_isdouble_simple(const char *s);

#endif