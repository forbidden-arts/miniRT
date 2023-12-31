/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_quad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:53:58 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/22 15:00:29 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "v3d.h"

/* Okay, so here is the math required to sort out how many roots a quadratic
	equation has. The swap double func at the bottom was included because we
	can only see the first time a ray intersects (may need to flip the
	inequality) since we can't see the backside of objects. */
BOOL	solve_quadratic(
	t_v3d params,
	double *t0,
	double *t1)
{
	double	discriminant;

	discriminant = pow(params.e[1], 2) - 4 * params.e[0] * params.e[2];
	if (discriminant < EPSILON)
		return (FALSE);
	*t0 = (-params.e[1] + sqrt(discriminant)) / (2 * params.e[0]);
	*t1 = (-params.e[1] - sqrt(discriminant)) / (2 * params.e[0]);
	return (TRUE);
}
