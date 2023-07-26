/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:24:01 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/26 14:47:15 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"
#include "object.h"
#include "v3d.h"

static BOOL	parse_sphere_check_parts(char *token, t_object *sphere, int *i)
{
	char	token_copy;

	while (token)
	{
		if (*i == 0)
			if (!check_identifier(token, SPHERE_ID))
				return (return_err("Unknown element type", NULL));
		else if (*i == 1)
			if (!coordinate_checkset(ft_strdup(token), &sphere->point))
				return (FALSE);
		else if (*i == 2)
			if (!dimension_checkset(token, &sphere->radius, TRUE))
				return (FALSE);
		else if (*i == 3)
			if (!color_checkset(ft_strdup(token), &sphere->color))
				return (FALSE);
		token = ft_strtok(NULL, " \t\n");
		*i++;
	}
	return (TRUE);
}

BOOL	parse_sphere(char *line, t_scene *scene, int index)
{
	t_object	*sphere;
	int			i;
	char		*token;

	i = 0;
	sphere = &scene->objects[index];
	sphere->type = SPHERE;
	token = ft_strtok(line, " \t\n");
	if (!parse_sphere_check_parts(token, sphere, &i))
		return (free_str_and_return_false(line));
	if (i != 4)
		return (return_err("Incorrect format in sphere data", line));
	free(line);
	line = NULL;
	return (TRUE);
}
