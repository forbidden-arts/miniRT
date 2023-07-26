/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:44:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/26 14:53:50 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	This function will print out the error message and return FALSE

	You can also give it an optional string that it will free.
	Leave the string as NULL otherwise (this part is for saving
	precious space in the functions this function is used in)
	*/
BOOL	return_err(char *error_msg, char *optional_str_to_free)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	if (optional_str_to_free)
		free(optional_str_to_free);
	return (FALSE);
}

/*	This function is used to free the given string and return NULL
	Used or saving precious space in the functions this is called in. */
BOOL	free_str_and_return_false(char *str)
{
	if (str)
		free(str);
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

/*	This function checks (and sets) a part of color data during parsing.
	
	If an error is encountered prints error and returns FALSE.*/
BOOL	color_part_checkset(char *str, double *target_data)
{
	int	result;

	if (ft_isinteger(str) == FALSE)
		return_err("Not a valid integer in color data", NULL);
	result = ft_atoi(str);
	if (result < 0 || result > 255)
		return_err("Color value not in bounds [0, 255]", NULL);
	*target_data = result;
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
	if (str == NULL)
		return (FALSE);
	while (str[++i])
		if (str[i] == c)
			char_count++;
	if (char_count == correct_amount)
		return (TRUE);
	return (FALSE);
}
