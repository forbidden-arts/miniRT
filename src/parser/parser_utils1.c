/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:44:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 16:05:14 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function will print out the error message and return FALSE*/
BOOL	return_err(char *error_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	return (FALSE);
}

/* this is function to check if the given string is an integer.*/
BOOL	ft_isinteger(char *s)
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
	if (!digit_found)
		return (FALSE);
	return (TRUE);
}

/*	This function simply checks that the color data is an integer
	and that it is in the bounds [0,255].
	If an error is encountered goes to error_exit().
	
	Used inside color_checkset.*/
BOOL	check_color(char *color_data)
{
	int	result;

	if (!ft_isinteger(color_data))
		return_err("Not a valid integer in color data");
	result = ft_atoi(color_data);
	if (result < 0 || result > 255)
		return_err("Color value not in bounds [0, 255]");
	return (TRUE);
}

/*	this function is used to check that there aren't too many or few
	of a certain char in a string.
	
	Use with coordinates, colors etc to check that there are the
	correct amount of commas. */
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
