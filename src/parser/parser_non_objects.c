/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_non_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:42:57 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/24 10:51:45 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "scene.h"
#include "object.h"
#include "globals.h"
#include <stdio.h>

/*	Ask Dan, do you set the object's normalized or axis value? */
void	parse_camera(t_parser *f)
{
	t_object	*camera;
	int			fov_value;

	f->error_part = f->line;
	if (str_array_count_strings(f->line_parts_array) != 4)
		error_exit("Incorrect amount of element data parts", f);
	if (create_object_and_add_to_lst_end(&g_scene.cameras) == FALSE)
		error_exit("Malloc failure when creating element object", f);
	camera = ft_lstlast(g_scene.cameras)->content;
	camera->is_camera = TRUE;
	coordinate_checkset(f->line_parts_array[1], &camera->point, f);
	three_d_normalized_vector_checkset(f->line_parts_array[2],
		&camera->normalized, f);
	f->error_part = f->line_parts_array[3];
	if (ft_isinteger(f->line_parts_array[3]) == FALSE)
		error_exit("Given value is not a valid integer", f);
	fov_value = ft_atoi(f->line_parts_array[3]);
	if (fov_value < 0 || fov_value > 180)
		error_exit("Given FOV value is not in bounds [0,180]", f);
	camera->field_of_view = fov_value;
}

void	parse_ambient_light(t_parser *f)
{
	f->error_part = f->line;
	if (f->ambient_light_bool == TRUE)
		error_exit("More than one ambient light element given in file", f);
	f->ambient_light_bool = TRUE;
	if (str_array_count_strings(f->line_parts_array) != 3)
		error_exit("Incorrect amount of element data parts", f);
	brightness_ratio_checkset(f->line_parts_array[1],
		&g_scene.ambient_intensity, f);
	color_checkset(f->line_parts_array[2], &g_scene.ambient_color, f);
}

void	parse_light(t_parser *f)
{
	t_object	*light;

	f->error_part = f->line;
	if (str_array_count_strings(f->line_parts_array) != 4)
		error_exit("Incorrect amount of element data parts", f);
	if (create_object_and_add_to_lst_end(&g_scene.lights) == FALSE)
		error_exit("Malloc failure when creating element object", f);
	light = ft_lstlast(g_scene.lights)->content;
	light->is_light = TRUE;
	coordinate_checkset(f->line_parts_array[1], &light->point, f);
	brightness_ratio_checkset(f->line_parts_array[2], &light->intensity, f);
	color_checkset(f->line_parts_array[3], &light->color, f);
}
