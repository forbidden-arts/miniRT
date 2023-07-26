/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_double_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:04:35 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 16:15:30 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static BOOL	parse_fraction(const char **s)
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
BOOL	ft_isdouble_simple(const char *s)
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
		if (!parse_fraction(&s))
			return (FALSE);
		c = *s;
	}
	if (*s == '\0' || *s == '\n')
		return (TRUE);
	return (FALSE);
}

static double	parse_fraction(const char **s, int *e)
{
	double	fraction;
	int		c;

	fraction = 0.0;
	while (1)
	{
		c = *(*s);
		if (!ft_isdigit(c))
			break ;
		fraction = fraction * 10.0 + (c - '0');
		*e -= 1;
		(*s)++;
	}
	return (fraction);
}

static int	check_sign(const char **s)
{
	int	sign;

	sign = 1;
	if (**s == '-')
	{
		sign = -1;
		(*s)++;
	}
	else if (**s == '+')
		(*s)++;
	return (sign);
}

/*	this is a simplified atof, it cannot handle anything
	involving exponents (symbols e or E). Also doesn't skip whitespace. */
double	ft_atof_simple(const char *s)
{
	double	a;
	int		e;
	int		c;
	int		sign;

	a = 0.0;
	e = 0;
	sign = check_sign(&s);
	while (1)
	{
		c = *s;
		if (!ft_isdigit(c))
			break ;
		a = a * 10.0 + (c - '0');
		s++;
	}
	if (c == '.')
	{
		s++;
		a += parse_fraction(&s, &e);
	}
	while (e++ < 0)
		a *= 0.1;
	return (a * sign);
}
