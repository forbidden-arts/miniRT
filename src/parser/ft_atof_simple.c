/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:01:35 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/20 12:13:17 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*	this is a simplified atof, it cannot handle anything
	involving exponents (symbols e or E). Also doesn't skip whitespace. */
double	ft_atof_simple(const char *s)
{
	double	a;
	int		e;
	int		c;

	a = 0.0;
	e = 0;
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
	return (a);
}
