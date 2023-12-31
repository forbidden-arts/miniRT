/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:17:45 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/22 14:39:25 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"
#include "v3d.h"

static BOOL	parse_plane_check_parts1(
	char **token,
	t_object *plane,
	int *i)
{
	while (*token && *i <= 2)
	{
		if (*i == 0)
		{
			if (!check_identifier(*token, PLANE_ID))
				return (return_err("Unknown element type", NULL));
		}
		else if (*i == 1)
		{
			if (!coordinate_checkset(*token, &plane->point))
				return (FALSE);
		}
		else if (*i == 2)
		{
			if (!axis_checkset(*token, &plane->axis))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

static BOOL	parse_plane_check_parts2(
	char **token,
	t_object *plane,
	int *i)
{
	while (*token)
	{
		if (*i == 3)
		{
			if (!color_checkset(*token, &plane->color))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

BOOL	parse_plane(
	char *line,
	t_scene *scene,
	int index)
{
	t_object	*plane;
	int			i;
	char		*token;

	if (!line)
		return (return_err("ft_strdup malloc failure", NULL));
	i = 0;
	plane = &scene->objects[index];
	plane->type = PLANE;
	token = ft_strtok(line, " \t\n");
	if (!parse_plane_check_parts1(&token, plane, &i))
		return (free_str_and_return_false(line));
	if (i != 3)
		return (return_err("Incorrect format in plane data", line));
	if (!parse_plane_check_parts2(&token, plane, &i))
		return (free_str_and_return_false(line));
	if (i != 4)
		return (return_err("Incorrect format in plane data", line));
	free(line);
	line = NULL;
	return (TRUE);
}
