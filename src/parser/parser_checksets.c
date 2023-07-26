/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checksets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:28:34 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/26 13:45:07 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "v3d.h"

/*
	BE AWARE: In the functions that check for data that has multiple parts
	like color or coordinates (0,0,0), you pass a malloced copy of the original
	line_part (done because of how strtok works).

	It is vital that you always free that string when exiting the function
	because otherwise it will cause a leak!
*/

/*	This function checks and sets the given objects color data.	*/
BOOL	color_checkset(char *str, t_v3d *target_data)
{
	char	*token;
	int		i;

	if (check_char_amount_in_str(str, ',', 2) == FALSE)
		return_err("Incorrect format in color-data", str);
	token = ft_strtok(str, ",");
	i = 0;
	while (token)
	{
		if (i == 0)
			if (!color_part_checkset(token, &target_data->x))
				return (free_str_and_return_false(str));
		else if (i == 1)
			if (!color_part_checkset(token, &target_data->y))
				return (free_str_and_return_false(str));
		else if (i == 2)
			if (!color_part_checkset(token, &target_data->z))
				return (free_str_and_return_false(str));
		token = ft_strtok(NULL, ",");
		i++;
	}
	if (i != 3)
		return (return_err("Incorrect format in color-data", str));
	return (TRUE);
}

/*	This function checks and sets the object's coordinate data.	*/
BOOL	coordinate_checkset(char *str, t_v3d *target_data)
{
	char	*token;
	int		i;

	if (check_char_amount_in_str(str, ',', 2) == FALSE)
		return_err("Incorrect format in coordinate-data", str);
	token = ft_strtok(str, ",");
	i = 0;
	while (token)
	{
		if (i == 0)
			if (!coordinate_part_checkset(token, &target_data->x))
				return (free_str_and_return_false(str));
		else if (i == 1)
			if (!coordinate_part_checkset(token, &target_data->y))
				return (free_str_and_return_false(str));
		else if (i == 2)
			if (!coordinate_part_checkset(token, &target_data->z))
				return (free_str_and_return_false(str));
		token = ft_strtok(NULL, ",");
		i++;
	}
	if (i != 3)
		return (return_err("Incorrect format in coordinate-data", str));
	return (TRUE);
}

/*	this function checks and sets the axis (3D normalized vector)
	for an object.	*/
BOOL	axis_checkset(char *str, t_v3d *target_data)
{
	char	*token;
	int		i;

	if (check_char_amount_in_str(str, ',', 2) == FALSE)
		return_err("Incorrect format in axis-data", str);
	token = ft_strtok(str, ",");
	i = 0;
	while (token)
	{
		if (i == 0)
			if (!axis_part_checkset(token, &target_data->x))
				return (free_str_and_return_false(str));
		else if (i == 1)
			if (!axis_part_checkset(token, &target_data->y))
				return (free_str_and_return_false(str));
		else if (i == 2)
			if (!axis_part_checkset(token, &target_data->z))
				return (free_str_and_return_false(str));
		token = ft_strtok(NULL, ",");
		i++;
	}
	if (i != 3)
		return (return_err("Incorrect format in axis-data", str));
	return (TRUE);
}

/*	This function checks the data that represents brightness. */
BOOL	brightness_ratio_checkset(char *str, double *target_data)
{
	double	result;

	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double in brighteness data", NULL));
	result = ft_atof_simple(str);
	if (result > 1.0 || result < 0)
		return (return_err("Brightness value not in bounds [0.0,1.0]", NULL));
	*target_data = result;
	return (TRUE);
}

/*	This function checks and sets a certain dimension, like height or radius,
	for an object.

	If diameter BOOL is TRUE, then we half the resulting double	*/
BOOL	dimension_checkset(char *str, double *target_data, BOOL diameter)
{
	double	result;

	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double in dimension data", NULL));
	result = ft_atof_simple(str);
	if (result <= 0)
		return (return_err("Dimension value must be greater than 0", NULL));
	if (diameter == TRUE)
		*target_data = result / 2;
	else
		*target_data = result;
	return (TRUE);
}
