/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:50:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/24 10:54:59 by dpalmer          ###   ########.fr       */
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

/* Takes a vec3d struct and returns separate struct of the normalized values */
t_v3d	normalize_vector(t_v3d input)
{
	t_v3d	normal;
	double	len;

	len = vector_len(input);
	normal.x = input.x / len;
	normal.y = input.y / len;
	normal.z = input.z / len;
	return (normal);
}

/* Used to calculate the length of a vector in a 3D plane */
double	vector_len(t_v3d input)
{
	return (sqrt(input.x * input.x + input.y * input.y + input.z * input.z));
}
