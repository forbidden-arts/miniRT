/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:35:44 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/22 14:49:36 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strings_in_array(
	char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		i++;
	}
	return (i);
}

/*	this function checks if the string is empty (only whitespace).
	(Used in find_non_shape_match) */
BOOL	check_if_empty_line(
	char *str)
{
	char	*token;

	token = ft_strtok(str, " \t\n");
	if (token)
		return (FALSE);
	return (TRUE);
}
