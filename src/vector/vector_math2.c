/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:22:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/31 17:55:52 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3d.h"

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

/* Okay, so here is the math required to sort out how many roots a quadratic
	equation has. The swap double func at the bottom was included because we
	can only see the first time a ray intersects (may need to flip the
	inequality) since we can't see the backside of objects. */
BOOL	solve_quadratic(t_v3d params, double *t0, double *t1)
{
	double	discriminant;

	discriminant = pow(params.y, 2) - 4 * params.x * params.z;
	if (discriminant < 0)
		return (FALSE);
	if (discriminant == 0)
	{
		*t0 = -params.y / (2 * params.x);
		*t1 = -params.y / (2 * params.x);
	}
	else
	{
		*t0 = (-params.y + sqrt(discriminant)) / (2 * params.x);
		*t1 = (-params.y - sqrt(discriminant)) / (2 * params.x);
	}
	if (*t0 > *t1)
		swap_double(t0, t1);
	return (TRUE);
}
