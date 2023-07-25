/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checksets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:28:34 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 12:00:17 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "v3d.h"

/*	This function checks and sets the given objects color data.

	If an error is encountered, prints out error and exits the program. */
void	color_checkset(char *str, int *target_elems_data, t_parser *f,
	t_scene *s)
{
	int		i;

	f->error_part = str;
	f->element_parts_array = ft_split(str, ',');
	if (!f->element_parts_array)
		error_exit("ft_split malloc failure", f, s);
	if (str_array_count_strings(f->element_parts_array) != 3
		|| check_char_amount_in_str(str, ',', 2) == FALSE)
		error_exit("Element color data in incorrect format", f, s);
	i = -1;
	while (++i < 3)
		check_color(f->element_parts_array[i], f, s);
	*target_elems_data = ft_atoi(f->element_parts_array[0]) << 16
		| ft_atoi(f->element_parts_array[1]) << 8
		| ft_atoi(f->element_parts_array[2]);
	str_array_free_everything(f->element_parts_array);
	f->element_parts_array = NULL;
}

/*	This function checks and sets the object's coordinate data.

	If an error is encountered, prints out error and exits the program. */
void	coordinate_checkset(char *str, t_v3d *target_elems_data,
	t_parser *f, t_scene *s)
{
	int	i;

	f->error_part = str;
	f->element_parts_array = ft_split(str, ',');
	if (!f->element_parts_array)
		error_exit("ft_split malloc failure", f, s);
	if (str_array_count_strings(f->element_parts_array) != 3
		|| check_char_amount_in_str(str, ',', 2) == FALSE)
		error_exit("Element coordinate data in incorrect format", f, s);
	i = -1;
	while (++i < 3)
		if (ft_isdouble_simple(f->element_parts_array[i]) == FALSE)
			error_exit("Not a valid double", f, s);
	target_elems_data->x = ft_atof_simple(f->element_parts_array[0]);
	target_elems_data->y = ft_atof_simple(f->element_parts_array[1]);
	target_elems_data->z = ft_atof_simple(f->element_parts_array[2]);
	str_array_free_everything(f->element_parts_array);
	f->element_parts_array = NULL;
}

/*	this function checks and sets the 3D normalized vector for an object.

	If an error is encountered, prints out error and exits the program. */
void	three_d_normalized_vector_checkset(char *str, t_v3d *target_elems_data,
	t_parser *f, t_scene *s)
{
	int	i;

	f->error_part = str;
	f->element_parts_array = ft_split(str, ',');
	if (!f->element_parts_array)
		error_exit("ft_split malloc failure", f, s);
	if (str_array_count_strings(f->element_parts_array) != 3
		|| check_char_amount_in_str(str, ',', 2) == FALSE)
		error_exit("Element 3d norm. vector data in incorrect format", f, s);
	i = -1;
	while (++i < 3)
	{
		if (ft_isdouble_simple(f->element_parts_array[i]) == FALSE)
			error_exit("Not a valid double", f, s);
		if (ft_atof_simple(f->element_parts_array[i]) < -1
			|| ft_atof_simple(f->element_parts_array[i]) > 1)
			error_exit("3d norm. vector value not in bounds [-1.0,1.0]", f, s);
	}
	target_elems_data->x = ft_atof_simple(f->element_parts_array[0]);
	target_elems_data->y = ft_atof_simple(f->element_parts_array[1]);
	target_elems_data->z = ft_atof_simple(f->element_parts_array[2]);
	str_array_free_everything(f->element_parts_array);
	f->element_parts_array = NULL;
}

/*	This function checks the data that represents brightness. */
void	brightness_ratio_checkset(char *str, double *target_elems_data,
	t_parser *f, t_scene *s)
{
	double	result;

	f->error_part = str;
	if (ft_isdouble_simple(str) == FALSE)
		error_exit("Brightness value not a valid double", f, s);
	result = ft_atof_simple(str);
	if (result > 1.0 || result < 0)
		error_exit("Brightness value not in bounds [0.0,1.0]", f, s);
	*target_elems_data = result;
}

/*	This function checks and sets a certain dimension, like height or radius,
	for an object.

	If the given value describes the diameter for an object, the value must
	be divided by two and set for the object in the function that calls this
	function.
	
	If an error is encountered, prints out error and exits the program. */
void	object_dimension_checkset(char *str, double *target_elems_data,
	t_parser *f, t_scene *s)
{
	double	result;

	f->error_part = str;
	if (ft_isdouble_simple(str) == FALSE)
		error_exit("Given value is not a valid double", f, s);
	result = ft_atof_simple(str);
	if (result <= 0)
		error_exit("The dimension of an object must be greater than zero",
			f, s);
	*target_elems_data = result;
}
