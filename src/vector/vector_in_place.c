/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math_in_place.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:00 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/01 11:48:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "v3d.h"

void	v3d_add_in_place(t_v3d *v, const t_v3d *other)
{
	v->e[0] += other->e[0];
	v->e[1] += other->e[1];
	v->e[2] += other->e[2];
}

void	v3d_multiply_in_place(t_v3d *v, double t)
{
	v->e[0] *= t;
	v->e[1] *= t;
	v->e[2] *= t;
}

void	v3d_divide_in_place(t_v3d *v, double t)
{
	v3d_multiply_in_place(v, 1.0 / t);
}
