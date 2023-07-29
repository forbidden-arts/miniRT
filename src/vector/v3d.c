/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:50:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/28 12:25:47 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "v3d.h"

/* Takes 3 doubles as input and returns them as a vec3d struct*/
t_v3d	init_v3d(double x, double y, double z)
{
	t_v3d	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

/* Needed for swapping roots if there are two REAL answers*/
void	swap_double(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
