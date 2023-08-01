/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:41:02 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/31 17:45:11 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"

static BOOL	parse_ambient_check_parts(char **token, t_ambient *ambient, int *i)
{
	while (*token)
	{
		if (*i == 0)
		{
			if (!check_identifier(*token, AMBIENT_LIGHT_ID))
				return (return_err("Unknown element type", NULL));
		}
		else if (*i == 1)
		{
			if (!brightness_ratio_checkset(*token, &ambient->intensity))
				return (FALSE);
		}
		else if (*i == 2)
		{
			if (!color_checkset(*token, &ambient->color))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

BOOL	parse_ambient(char *line, t_scene *scene)
{
	t_ambient	*ambient;
	int			i;
	char		*token;

	if (!line)
		return (return_err("ft_strdup malloc failure", NULL));
	i = 0;
	ambient = &scene->ambient;
	token = ft_strtok(line, " \t\n");
	if (!parse_ambient_check_parts(&token, ambient, &i))
		return (free_str_and_return_false(line));
	if (i != 3)
		return (return_err("Incorrect format in ambient data", line));
	free(line);
	line = NULL;
	return (TRUE);
}
