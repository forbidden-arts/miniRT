/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_quad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:53:58 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/29 11:22:42 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ray.h"
#include "v3d.h"

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
