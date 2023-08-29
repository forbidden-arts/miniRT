/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:35:44 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/29 13:27:20 by ssalmi           ###   ########.fr       */
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

BOOL	check_if_empty_line(
	char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(" \t\n", str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
