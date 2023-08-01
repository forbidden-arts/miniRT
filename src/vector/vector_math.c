/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:22:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/01 14:17:32 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3d.h"

double	v3d_length(const t_v3d *v)
{
	return (sqrt(v3d_length_squared(v)));
}

double	v3d_length_squared(const t_v3d *v)
{
	return (v->e[0] * v->e[0] + v->e[1] * v->e[1] + v->e[2] * v->e[2]);
}

double	v3d_dot(const t_v3d *u, const t_v3d *v)
{
	return (u->e[0] * v->e[0] + u->e[1] * v->e[1] + u->e[2] * v->e[2]);
}

t_v3d	v3d_cross(const t_v3d *u, const t_v3d *v)
{
	t_v3d	result;

	result.e[0] = u->e[1] * v->e[2] - u->e[2] * v->e[1];
	result.e[1] = u->e[2] * v->e[0] - u->e[0] * v->e[2];
	result.e[2] = u->e[0] * v->e[1] - u->e[1] * v->e[0];
	return (result);
}

t_v3d	v3d_unit_vector(t_v3d *v)
{
	double	len;

	len = v3d_length(v);
	return (v3d_divide_scalar(v, len));
}
