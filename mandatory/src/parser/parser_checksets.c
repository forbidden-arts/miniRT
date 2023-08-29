/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checksets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:28:34 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/29 13:26:18 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "v3d.h"
#include "color.h"

BOOL	color_checkset(
	char *str,
	t_v3d *target_data)
{
	char	**split_array;

	split_array = ft_split(str, ',');
	if (!split_array)
		return (return_err("ft_split malloc failure", NULL));
	if (count_strings_in_array(split_array) != 3
		|| check_char_amount_in_str(str, ',', 2) == FALSE)
	{
		free_str_array_and_return_false(split_array);
		return (return_err("Incorrect format in color-data", NULL));
	}
	if (!color_part_checkset(split_array[0], &target_data->e[0]))
		return (free_str_array_and_return_false(split_array));
	if (!color_part_checkset(split_array[1], &target_data->e[1]))
		return (free_str_array_and_return_false(split_array));
	if (!color_part_checkset(split_array[2], &target_data->e[2]))
		return (free_str_array_and_return_false(split_array));
	free_str_array_and_return_false(split_array);
	normalize_rgb(target_data);
	return (TRUE);
}

BOOL	coordinate_checkset(
	char *str,
	t_v3d *target_data)
{
	char	**split_array;

	split_array = ft_split(str, ',');
	if (!split_array)
		return (return_err("ft_split malloc failure", NULL));
	if (count_strings_in_array(split_array) != 3
		|| check_char_amount_in_str(str, ',', 2) == FALSE)
	{
		free_str_array_and_return_false(split_array);
		return (return_err("Incorrect format in coordinate-data", NULL));
	}
	if (!coordinate_part_checkset(split_array[0], &target_data->e[0]))
		return (free_str_array_and_return_false(split_array));
	if (!coordinate_part_checkset(split_array[1], &target_data->e[1]))
		return (free_str_array_and_return_false(split_array));
	if (!coordinate_part_checkset(split_array[2], &target_data->e[2]))
		return (free_str_array_and_return_false(split_array));
	target_data->e[2] *= -1.0;
	free_str_array_and_return_false(split_array);
	return (TRUE);
}

BOOL	axis_checkset(
	char *str,
	t_v3d *target_data)
{
	char	**split_array;

	split_array = ft_split(str, ',');
	if (!split_array)
		return (return_err("ft_split malloc failure", NULL));
	if (count_strings_in_array(split_array) != 3
		|| check_char_amount_in_str(str, ',', 2) == FALSE)
	{
		free_str_array_and_return_false(split_array);
		return (return_err("Incorrect format in axis-data", NULL));
	}
	if (!axis_part_checkset(split_array[0], &target_data->e[0]))
		return (free_str_array_and_return_false(split_array));
	if (!axis_part_checkset(split_array[1], &target_data->e[1]))
		return (free_str_array_and_return_false(split_array));
	if (!axis_part_checkset(split_array[2], &target_data->e[2]))
		return (free_str_array_and_return_false(split_array));
	target_data->e[2] *= -1.0;
	free_str_array_and_return_false(split_array);
	*target_data = v3d_unit_vector(target_data);
	return (TRUE);
}

BOOL	brightness_ratio_checkset(
	char *str,
	double *target_data)
{
	double	result;

	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double in brighteness data", NULL));
	result = ft_atod(str);
	if (result > 1.0 || result < 0)
		return (return_err("Brightness value not in bounds [0.0,1.0]", NULL));
	*target_data = result;
	return (TRUE);
}

BOOL	dimension_checkset(
	char *str,
	double *target_data,
	BOOL diameter)
{
	double	result;

	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double in dimension data", NULL));
	result = ft_atod(str);
	if (result <= 0)
		return (return_err("Dimension value must be greater than 0", NULL));
	if (diameter == TRUE)
		*target_data = result / 2;
	else
		*target_data = result;
	return (TRUE);
}
