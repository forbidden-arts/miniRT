/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:20:04 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/10 11:54:53 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "scene.h"

static BOOL	camera_fov_checkset(char *str, double *target_data)
{
	int	result;

	if (ft_isinteger(str) == FALSE)
		return (return_err("Camera FOV not valid integer", NULL));
	result = ft_atoi(str);
	if (result < 0 || result > 180)
		return (return_err("Camera FOV not in bounds [0,180]", NULL));
	*target_data = result;
	return (TRUE);
}

static BOOL	parse_camera_check_parts1(char **token, t_camera *camera, int *i)
{
	while (*token && *i <= 2)
	{
		if (*i == 0)
		{
			if (!check_identifier(*token, CAMERA_ID))
				return (return_err("Unknown element type", NULL));
		}
		else if (*i == 1)
		{
			if (!coordinate_checkset(*token, &camera->location))
				return (FALSE);
		}
		else if (*i == 2)
		{
			if (!axis_checkset(*token, &camera->direction))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

static BOOL	parse_camera_check_parts2(char **token, t_camera *camera, int *i)
{
	while (*token)
	{
		if (*i == 3)
		{
			if (!camera_fov_checkset(*token, &camera->field_of_view))
				return (FALSE);
		}
		*token = ft_strtok(NULL, " \t\n");
		*i += 1;
	}
	return (TRUE);
}

BOOL	parse_camera(char *line, t_scene *scene, int index)
{
	t_camera	*camera;
	int			i;
	char		*token;

	if (!line)
		return (return_err("ft_strdup malloc failure", NULL));
	i = 0;
	camera = &scene->cameras[index];
	token = ft_strtok(line, " \t\n");
	if (!parse_camera_check_parts1(&token, camera, &i))
		return (free_str_and_return_false(line));
	if (i != 3)
		return (return_err("Incorrect format in camera data", line));
	if (!parse_camera_check_parts2(&token, camera, &i))
		return (free_str_and_return_false(line));
	if (i != 4)
		return (return_err("Incorrect format in camera data", line));
	free(line);
	line = NULL;
	return (TRUE);
}
