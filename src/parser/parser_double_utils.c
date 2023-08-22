/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_double_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:04:35 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/22 14:40:48 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static BOOL	parse_fraction_isdouble(
	const char **s)
{
	BOOL	has_fraction;
	int		c;

	has_fraction = FALSE;
	while (1)
	{
		c = *(*s);
		if (!ft_isdigit(c))
			break ;
		has_fraction = TRUE;
		(*s)++;
	}
	return (has_fraction);
}

/*	this is a function that checks if the given string is a double.
	It doesn't recognize exponents. Also doesn't skip whitespaces. */
BOOL	ft_isdouble_simple(
	const char *s)
{
	int	c;

	c = *s;
	if (c == '+' || c == '-')
		s++;
	while (1)
	{
		c = *s;
		if (!ft_isdigit(c))
			break ;
		s++;
	}
	if (c == '.')
	{
		s++;
		if (!parse_fraction_isdouble(&s))
			return (FALSE);
		c = *s;
	}
	if (*s == '\0' || *s == '\n')
		return (TRUE);
	return (FALSE);
}
