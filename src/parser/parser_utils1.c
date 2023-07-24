/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:34:03 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/21 16:20:04 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_array_free_everything(char **str_array)
{
	int	i;

	i = -1;
	while (str_array[++i])
		free(str_array[i]);
	free(str_array);
}

/*	this function simply frees the given str-array and returns the given
	code. Used to save precious space. */
int	free_str_array_and_return_code(char **str_array, int code)
{
	str_array_free_everything(str_array);
	return (code);
}

/*	this function is used to check that there aren't too many or few
	of a certain char in a string.*/
BOOL	check_char_amount_in_str(char *str, char c, int correct_amount)
{
	int	i;
	int	char_count;

	char_count = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			char_count++;
	if (char_count == correct_amount)
		return (TRUE);
	return (FALSE);
}

/* this is function to check if the given string is an integer.*/
int	ft_isinteger(char *s)
{
	int	digit_found;
	int	i;

	digit_found = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (i == 0 && (s[i] == '+' || s[i] == '-'))
			continue ;
		if (ft_isdigit(s[i]))
			digit_found = 1;
		else
			return (0);
		i++;
	}
	return (digit_found);
}

/*	this function returns the amount of strings in
	a null-terminating string array. */
int	str_array_count_strings(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
		i++;
	return (i);
}
