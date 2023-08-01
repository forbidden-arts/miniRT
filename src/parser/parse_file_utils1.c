/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:32:49 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/31 17:54:29 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "libft.h"
#include "parser.h"
#include "scene.h"

int	get_fd(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		perror("Error\nCan not open file");
	return (fd);
}

BOOL	check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len <= 3)
	{
		ft_putendl_fd("Error\nInvalid file given (must be a valid .rt-file)", 2);
		return (FALSE);
	}
	if (!ft_strncmp(&argv[len - 3], ".rt", 4))
		return (TRUE);
	ft_putendl_fd("Error\nInvalid file given (must be a valud .rt-file)", 2);
	return (FALSE);
}

/*	This function handles the initiation of the file_parser-struct
	and also open the file for get_next_line. */
BOOL	init_file_parser_struct(t_file_parser *file_parser, char *argv)
{
	file_parser->ambient_light_found = FALSE;
	file_parser->index_camera = 0;
	file_parser->index_light = 0;
	file_parser->index_sphape = 0;
	file_parser->result = TRUE;
	file_parser->fd = get_fd(argv);
	if (file_parser->fd < 0)
		return (FALSE);
	return (TRUE);
}

BOOL	find_shape_match(t_file_parser *p, t_scene *scene)
{
	if (!ft_strncmp(p->line, SPHERE_ID, 2))
	{
		p->result = parse_sphere(ft_strdup(p->line), scene, p->index_sphape++);
		return (TRUE);
	}
	else if (!ft_strncmp(p->line, PLANE_ID, 2))
	{
		p->result = parse_plane(ft_strdup(p->line), scene, p->index_sphape++);
		return (TRUE);
	}
	else if (!ft_strncmp(p->line, CYLINDER_ID, 2))
	{
		p->result = parse_cylinder(ft_strdup(p->line), scene,
				p->index_sphape++);
		return (TRUE);
	}
	return (FALSE);
}

BOOL	find_non_shape_match(t_file_parser *p, t_scene *scene)
{
	if (!ft_strncmp(p->line, CAMERA_ID, 1))
	{
		p->result = parse_camera(ft_strdup(p->line), scene, p->index_camera++);
		return (TRUE);
	}
	else if (!ft_strncmp(p->line, LIGHT_ID, 1))
	{
		p->result = parse_light(ft_strdup(p->line), scene, p->index_light++);
		return (TRUE);
	}
	else if (!ft_strncmp(p->line, AMBIENT_LIGHT_ID, 1))
	{
		if (p->ambient_light_found == FALSE)
			p->result = parse_ambient(ft_strdup(p->line), scene);
		else
			p->result = return_err("Too many ambient light elements in file",
					NULL);
		p->ambient_light_found = TRUE;
		return (TRUE);
	}
	else if (!ft_strncmp(p->line, "//", 2))
		return (TRUE);
	return (FALSE);
}
