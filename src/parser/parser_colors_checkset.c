/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors_checkset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:36:50 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/20 11:47:17 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

/* Print error? on >255*/
static BOOL	check_color(char *str)
{
	int	plus_bool;
	int	i;

	plus_bool = 0;
	i = -1;
	while (str[++i])
	{
		if (i == 0 && str[i] == '+')
			plus_bool = 1;
		else
			if (!ft_isdigit(str[i]))
				return (FALSE);
	}
	if (i == 4 && !plus_bool)
		return (FALSE);
	if (ft_atoi(str) > 255)
		return (FALSE);
	return (TRUE);
}

/*	This function checks that the given color data is correct. If it
	is not correct, returns a non-zero value. If it is, correct, set
	the target elements color and return 0. */
int	color_checkset(char *str, int *target_elems_data)
{
	char	**str_array;
	int		i;

	str_array = ft_split(str, ',');
	i = -1;
	while (str_array[++i] != NULL)
		if (check_color(str_array[i]) != 0)
			return (free_str_array_and_return_code(str_array, 1));
	if (i != 3 || check_char_amount_in_str(str, ',', 2))
		return (free_str_array_and_return_code(str_array, 2));
	*target_elems_data = ft_atoi(str_array[0]) << 16
		| ft_atoi(str_array[1]) << 8 | ft_atoi(str_array[2]);
	free_str_array_and_return_code(str_array, 0);
}
