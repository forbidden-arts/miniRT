/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:59:25 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/26 12:18:15 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

/*	This function checks (and sets) a part of coordinate data during parsing.
	
	If an error is encountered prints error and returns FALSE.*/
BOOL	coordinate_part_checkset(char *str, double *target_data)
{
	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double in coordinate-data", NULL));
	*target_data = ft_atof_simple(str);
	return (TRUE);
}

/*	This function checks (and sets) a part of axis data during parsing.
	
	If an error is encountered prints error and returns FALSE.*/
BOOL	axis_part_checkset(char *str, double *target_data)
{
	double	result;

	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double in coordinate-data", NULL));
	result = ft_atof_simple(str);
	if (result < -1 || result > 1)
		return (return_err("axis-data part not in bounds [-1.0,1.0]", NULL));
	*target_data = result;
	return (TRUE);
}

/*	This function checks (and sets) dimension data during parsing.
	
	If an error is encountered prints error and returns FALSE.*/
BOOL	dimension_checkset(char *str, double *target_data)
{
	double	result;

	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double for dimension-data", NULL));
	result = ft_atof_simple(str);
	if (result <= 0)
		return (return_err("A dimension must be greater than 0", NULL));
	*target_data = result;
	return (TRUE);
}
