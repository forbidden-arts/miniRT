/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:51:22 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/18 16:17:14 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define DELIMITERS		" \t"
# define AMBIENT_LIGHT	"A"
# define CAMERA		 	"C"
# define LIGHT			"L"
# define SPHERE		 	"sp"
# define CYLINDER	 	"cy"
# define PLANE		 	"pl"

typedef struct s_file_parser_function
{
	char	*line;
	char	*elem_type;
	int		ambient_light_bool;
	int		error;
}	t_file_parser_function;

// functions
int	file_handler(int argc, char **argv);

int	file_parser(int fd);

int	parse_camera(t_file_parser_function *f);
int	parse_ambient_light(t_file_parser_function *f);
int	parse_light(t_file_parser_function *f);
int	parse_sphere(t_file_parser_function *f);
int	parse_cylinder(t_file_parser_function *f);
int	parse_plane(t_file_parser_function *f);

int	parser_errors(t_file_parser_function *f);

#endif