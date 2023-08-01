/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:37:01 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/01 16:30:34 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

// rm later
#include <stdio.h>

static size_t	ft_atod_get_digits(int fraction)
{
	size_t	digit_amount;

	digit_amount = 0;
	if (fraction == 0)
		return (1);
	while (fraction > 0)
	{
		digit_amount++;
		fraction = fraction / 10;
	}
	return (digit_amount);
}

double	ft_atod(char *str)
{
	double	before;
	double	after;
	int		after_int;
	size_t	digits_after;

	before = (double)ft_atoi(str);
	if (!ft_strchr(str, '.'))
		return (before);
	while (*str != '.')
		str++;
	str++;
	after_int = ft_atoi(str);
	after = (double)after_int;
	if (after != 0)
	{
		digits_after = ft_atod_get_digits(after_int);
		while (digits_after-- > 0)
			after *= 0.1;
	}
	if (before < 0)
		return (before - after);
	return (before + after);
}
