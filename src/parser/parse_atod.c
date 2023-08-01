/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:37:01 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/01 15:01:29 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

double	ft_atod(char *str)
{
	size_t	before;
	size_t	after;

	before = (double)ft_atoi(str);
	if (!ft_strchr(str, '.'))
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
