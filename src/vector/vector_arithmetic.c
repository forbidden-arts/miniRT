/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:00 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/01 13:01:56 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3d.h"

t_v3d	v3d_add(const t_v3d *u, const t_v3d *v)
{
	t_v3d	result;

	result.e[0] = u->e[0] + v->e[0];
	result.e[1] = u->e[1] + v->e[1];
	result.e[2] = u->e[2] + v->e[2];
	return (result);
}

t_v3d	v3d_subtract(const t_v3d *u, const t_v3d *v)
{
	t_v3d	result;

	result.e[0] = u->e[0] - v->e[0];
	result.e[1] = u->e[1] - v->e[1];
	result.e[2] = u->e[2] - v->e[2];
	return (result);
}

t_v3d	v3d_multiply(const t_v3d *u, const t_v3d *v)
{
	t_v3d	result;

	result.e[0] = u->e[0] * v->e[0];
	result.e[1] = u->e[1] * v->e[1];
	result.e[2] = u->e[2] * v->e[2];
	return (result);
}

t_v3d	v3d_multiply_scalar(double t, const t_v3d *v)
{
	t_v3d	result;

	result.e[0] = t * v->e[0];
	result.e[1] = t * v->e[1];
	result.e[2] = t * v->e[2];
	return (result);
}

t_v3d	v3d_divide_scalar(double t, const t_v3d *v)
{
	return (v3d_multiply_scalar(1.0 / t, v));
}
