/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:36:52 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/23 12:59:49 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"
#include "v3d.h"

static BOOL	parse_cone_check_parts1(
	char **token,
	t_object *cone,
	int *i)
{
	while (*token && *i <= 2)
	{
		if (*i == 0)
		{
			if (!check_identifier(*token, CONE_ID))
				return (return_err("Unknown element type", NULL));
		}
		else if (*i == 1)
		{
			if (!coordinate_checkset(*token, &cone->point))
				return (FALSE);
		}
		else if (*i == 2)
		{
			if (!axis_checkset(*token, &cone->axis))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

static BOOL	parse_cone_check_parts2(
	char **token,
	t_object *cone,
	int *i)
{
	while (*token)
	{
		if (*i == 3)
		{
			if (!dimension_checkset(*token, &cone->radius, TRUE))
				return (FALSE);
		}
		else if (*i == 4)
		{
			if (!dimension_checkset(*token, &cone->height, FALSE))
				return (FALSE);
		}
		else if (*i == 5)
		{
			if (!color_checkset(*token, &cone->color))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

BOOL	parse_cone(
	char *line,
	t_scene *scene,
	int index)
{
	t_object	*cone;
	int			i;
	char		*token;

	if (!line)
		return (return_err("ft_strdup malloc failure", NULL));
	i = 0;
	cone = &scene->objects[index];
	cone->type = CONE;
	token = ft_strtok(line, " \t\n");
	if (!parse_cone_check_parts1(&token, cone, &i))
		return (free_str_and_return_false(line));
	if (i != 3)
		return (return_err("Incorrect format in cone data", line));
	if (!parse_cone_check_parts2(&token, cone, &i))
		return (free_str_and_return_false(line));
	if (i != 6)
		return (return_err("Incorrect format in cone data", line));
	free(line);
	line = NULL;
	return (TRUE);
}
