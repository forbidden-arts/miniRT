/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:35:24 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/01 10:30:56 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"
#include "v3d.h"

static BOOL	parse_light_check_parts1(char **token, t_light *light, int *i)
{
	while (*token && *i <= 2)
	{
		if (*i == 0)
		{
			if (!check_identifier(*token, LIGHT_ID))
				return (return_err("Unknown element type", NULL));
		}
		else if (*i == 1)
		{
			if (!coordinate_checkset(*token, &light->location))
				return (FALSE);
		}
		else if (*i == 2)
		{
			if (!brightness_ratio_checkset(*token, &light->intensity))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

static BOOL	parse_light_check_parts2(char **token, t_light *light, int *i)
{
	while (*token)
	{
		if (*i == 3)
		{
			if (!color_checkset(*token, &light->color))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

BOOL	parse_light(char *line, t_scene *scene, int index)
{
	t_light		*light;
	int			i;
	char		*token;

	if (!line)
		return (return_err("ft_strdup malloc failure", NULL));
	i = 0;
	light = &scene->lights[index];
	token = ft_strtok(line, " \t\n");
	if (!parse_light_check_parts1(&token, light, &i))
		return (free_str_and_return_false(line));
	if (i != 3)
		return (return_err("Incorrect format in light data", line));
	if (!parse_light_check_parts2(&token, light, &i))
		return (free_str_and_return_false(line));
	if (i != 4)
		return (return_err("Incorrect format in light data", line));
	free(line);
	line = NULL;
	return (TRUE);
}
