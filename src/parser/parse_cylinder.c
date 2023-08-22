/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:03:47 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/22 14:37:18 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"
#include "v3d.h"

static BOOL	parse_cylinder_check_parts1(
	char **token,
	t_object *cylinder,
	int *i)
{
	while (*token && *i <= 2)
	{
		if (*i == 0)
		{
			if (!check_identifier(*token, CYLINDER_ID))
				return (return_err("Unknown element type", NULL));
		}
		else if (*i == 1)
		{
			if (!coordinate_checkset(*token, &cylinder->point))
				return (FALSE);
		}
		else if (*i == 2)
		{
			if (!axis_checkset(*token, &cylinder->axis))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

static BOOL	parse_cylinder_check_parts2(
	char **token,
	t_object *cylinder,
	int *i)
{
	while (*token)
	{
		if (*i == 3)
		{
			if (!dimension_checkset(*token, &cylinder->radius, TRUE))
				return (FALSE);
		}
		else if (*i == 4)
		{
			if (!dimension_checkset(*token, &cylinder->height, FALSE))
				return (FALSE);
		}
		else if (*i == 5)
		{
			if (!color_checkset(*token, &cylinder->color))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

BOOL	parse_cylinder(
	char *line,
	t_scene *scene,
	int index)
{
	t_object	*cylinder;
	int			i;
	char		*token;

	if (!line)
		return (return_err("ft_strdup malloc failure", NULL));
	i = 0;
	cylinder = &scene->objects[index];
	cylinder->type = CYLINDER;
	token = ft_strtok(line, " \t\n");
	if (!parse_cylinder_check_parts1(&token, cylinder, &i))
		return (free_str_and_return_false(line));
	if (i != 3)
		return (return_err("Incorrect format in cylinder data", line));
	if (!parse_cylinder_check_parts2(&token, cylinder, &i))
		return (free_str_and_return_false(line));
	if (i != 6)
		return (return_err("Incorrect format in cylinder data", line));
	free(line);
	line = NULL;
	return (TRUE);
}
