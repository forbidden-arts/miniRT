/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:59:25 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/22 14:49:28 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

/*	This function checks (and sets) a part of coordinate data during parsing.
	
	If an error is encountered prints error and returns FALSE.*/
BOOL	coordinate_part_checkset(
	char *str,
	double *target_data)
{
	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double in coordinate-data", NULL));
	*target_data = ft_atod(str);
	return (TRUE);
}

/*	This function checks (and sets) a part of axis data during parsing.
	
	If an error is encountered prints error and returns FALSE.*/
BOOL	axis_part_checkset(
	char *str,
	double *target_data)
{
	double	result;

	if (ft_isdouble_simple(str) == FALSE)
		return (return_err("Not a valid double in coordinate-data", NULL));
	result = ft_atod(str);
	if (result < -1 || result > 1)
		return (return_err("axis-data part not in bounds [-1.0,1.0]", NULL));
	*target_data = result;
	return (TRUE);
}

/*	Check that the identifier is in the correct format	*/
BOOL	check_identifier(
	char *str,
	char *id)
{
	size_t	len_id;

	len_id = ft_strlen(id);
	if (ft_strlen(str) != len_id)
		return (FALSE);
	if (ft_strncmp(str, id, len_id) != 0)
		return (FALSE);
	return (TRUE);
}

// print the line where the error was encountered
void	print_error_line(
	char *line)
{
	ft_putstr_fd("Error in line: ", 2);
	ft_putstr_fd(line, 2);
}

BOOL	free_str_array_and_return_false(
	char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		ft_bzero(str_array[i], ft_strlen(str_array[i]));
		free(str_array[i]);
		i++;
	}
	free(str_array);
	return (FALSE);
}
