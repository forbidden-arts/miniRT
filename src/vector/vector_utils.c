/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:58:53 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/21 11:52:58 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3d.h"


t_v3d	v3d_negate(const t_v3d *v)
{
	t_v3d	result;

	result.e[0] = -v->e[0];
	result.e[1] = -v->e[1];
	result.e[2] = -v->e[2];
	return (result);
}

double	v3d_get_dist(const t_v3d *origin, const t_v3d *dest)
{
	t_v3d	temp;

	temp = v3d_subtract(origin, dest);
	return (v3d_length(&temp));
}

// double	v3d_get(const t_v3d *v, int i)
// {
// 	return (v->e[i]);
// }

// void	v3d_set(t_v3d *v, int i, double val)
// {
// 	v->e[i] = val;
// }

// void	swap_double(double *a, double *b)
// {
// 	double	temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// void	v3d_copy_data(t_v3d *dst, const t_v3d *src)
// {
// 	v3d_init_with_values(dst, src->e[0], src->e[1], src->e[2]);
// }
