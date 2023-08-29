/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:44:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/29 13:26:51 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	return_err(
	char *error_msg,
	char *optional_str_to_free)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	if (optional_str_to_free)
		free(optional_str_to_free);
	return (FALSE);
}

BOOL	free_str_and_return_false(
	char *str)
{
	if (str)
		free(str);
	return (FALSE);
}

BOOL	ft_isinteger(char *s)
{
	BOOL	digit_found;
	int		i;

	digit_found = FALSE;
	i = 0;
	while (s[i])
	{
		if (i == 0 && (s[i] == '+' || s[i] == '-'))
		{
			i++;
			continue ;
		}
		if (ft_isdigit(s[i]))
			digit_found = TRUE;
		else
			return (FALSE);
		i++;
	}
	if (!digit_found)
		return (FALSE);
	return (TRUE);
}

BOOL	color_part_checkset(
	char *str, double
	*target_data)
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

BOOL	check_char_amount_in_str(
	char *str,
	char c,
	int correct_amount)
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
