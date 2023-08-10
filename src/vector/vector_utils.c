/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:58:53 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/10 13:24:43 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3d.h"

double	v3d_get(const t_v3d *v, int i)
{
	return (v->e[i]);
}

void	v3d_set(t_v3d *v, int i, double val)
{
	v->e[i] = val;
}

t_v3d	v3d_negate(const t_v3d *v)
{
	t_v3d	result;

	result.e[0] = -v->e[0];
	result.e[1] = -v->e[1];
	result.e[2] = -v->e[2];
	return (result);
}
