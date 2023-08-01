/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:37:01 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/01 14:52:22 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

double	ft_atod(char *str)
{
	size_t	before;
	size_t	after;
	int		decimal;

	before = (double)ft_atoi(str);
	decimal = ft_strchr(str, '.');
	if (!decimal)
		return (before);
	while (*str != '.')
		str++;
	str++;
	after = (double)ft_atoi(str);
	after /= pow(10, (int)log10(after) + 1);
	if (before < 0)
		return (before - after);
	return (before + after);
}
