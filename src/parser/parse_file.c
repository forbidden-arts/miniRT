/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:08:23 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/25 16:54:30 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "scene.h"
#include "parser.h"

int	get_fd(char *argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		perror("Error\nCan not open file");
	return (fd);
}

BOOL	check_extension(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len <= 3)
		return (FALSE);
	if (!ft_strncmp(&argv[len - 3], ".rt", 4))
		return (FALSE);
	return (TRUE);
}

BOOL	count_scene(int fd, t_scene *scene)
{
	char	*line;

	while (TRUE)
	{
		line = ft_strtok(get_next_line(fd), " \t\n");
		if (!line)
			break ;
		if (!ft_strncmp(line, "L", 2))
			scene->n_lights++;
		else if (!ft_strncmp(line, "C", 2))
			scene->n_cameras++;
		else if (ft_strncmp(line, "//", 3))
			scene->n_objects++;
	}
	close(fd);
	return (TRUE);
}

BOOL	allocate_array_scene(t_scene *scene)
{
	scene->cameras = malloc(sizeof(t_camera) * scene->n_cameras);
	scene->lights = malloc(sizeof(t_camera) * scene->n_lights);
	scene->objects = malloc(sizeof(t_object) * scene->n_objects);
	if (!scene->cameras || !scene->lights || !scene->objects)
		return (FALSE);
	return (TRUE);
}

BOOL	populate_array_scene(t_scene *scene, char *argv)
{
	char	*line;
	int		fd;

	fd = get_fd(argv);
	if (fd < 0)
		return (FALSE);
	while (TRUE)
	{
		line =get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "sp", 2))
			if (!parse_sphere(line, scene))
			{
				// print the line where error happened
				// (the error msg was already printed)
				ft_putstr_fd("Error in line: ", 2);
				ft_putendl_fd(line, 2);
				// free some shit and quit.
			}
	}
	return (TRUE);
}
