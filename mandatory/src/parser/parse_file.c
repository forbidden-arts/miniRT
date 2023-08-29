/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:08:23 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/29 13:43:13 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "scene.h"
#include "parser.h"

static BOOL	count_scene(
	int fd,
	t_scene *scene)
{
	char	*line;
	char	*token;

	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		token = ft_strtok(line, " \t\n");
		if (token == NULL)
			;
		else if (!ft_strncmp(token, CAMERA_ID, 1))
			scene->n_cameras++;
		else if (!ft_strncmp(token, LIGHT_ID, 1))
			scene->n_lights++;
		else if (!ft_strncmp(token, AMBIENT_LIGHT_ID, 1))
			;
		else if (ft_strncmp(token, "//", 2))
			scene->n_objects++;
		free(line);
	}
	close(fd);
	return (TRUE);
}

static BOOL	allocate_array_scene(
	t_scene *scene)
{
	if (scene->n_cameras == 0)
		return (return_err("No camera elem(s) given in file", NULL));
	if (scene->n_cameras > 1)
		return (return_err("More than one camera given in file", NULL));
	if (scene->n_lights > 1)
		return (return_err("More than one light given in file", NULL));
	if (scene->n_objects == 0)
		return (return_err("No shape elem(s) given in file", NULL));
	scene->cameras = malloc(sizeof(t_camera) * scene->n_cameras);
	scene->lights = malloc(sizeof(t_camera) * scene->n_lights);
	scene->objects = malloc(sizeof(t_object) * scene->n_objects);
	if (!scene->cameras || !scene->lights || !scene->objects)
		return (FALSE);
	return (TRUE);
}

static BOOL	parsing_end_check(
	t_file_parser *parser)
{
	if (parser->ambient_light_found == FALSE)
		return (return_err("No ambient light elem given in file", NULL));
	return (TRUE);
}

BOOL	populate_array_scene(
	t_scene *scene,
	char *argv)
{
	t_file_parser	parser;
	BOOL			found_match;

	if (init_file_parser_struct(&parser, argv) == FALSE)
		return (FALSE);
	while (parser.result)
	{
		parser.line = get_next_line(parser.fd);
		if (!parser.line)
			break ;
		found_match = FALSE;
		found_match = find_shape_match(&parser, scene);
		if (found_match == FALSE)
			found_match = find_non_shape_match(&parser, scene);
		if (found_match == FALSE)
			parser.result = return_err("Unknown element type", NULL);
		if (parser.result == FALSE)
			print_error_line(parser.line);
		parser.line = free_str_and_set_as_null(parser.line);
	}
	close(parser.fd);
	if (parser.result == TRUE)
		parser.result = parsing_end_check(&parser);
	return (parser.result);
}

BOOL	minirt_start(
	int argc,
	char **argv,
	t_scene *scene)
{
	int	fd;

	if (argc != 2)
		return (FALSE);
	if (check_extension(argv[1]) == FALSE)
		return (FALSE);
	fd = get_fd(argv[1]);
	if (fd < 0)
		return (FALSE);
	count_scene(fd, scene);
	if (allocate_array_scene(scene) == FALSE)
		return (FALSE);
	if (populate_array_scene(scene, argv[1]) == FALSE)
		return (FALSE);
	return (TRUE);
}
