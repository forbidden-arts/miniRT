/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:50:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/22 14:57:01 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "v3d.h"

void	v3d_init(
	t_v3d *v)
{
	v->e[0] = 0;
	v->e[1] = 0;
	v->e[2] = 0;
}

void	v3d_init_with_values(
	t_v3d *v,
	double e0,
	double e1,
	double e2)
{
	v->e[0] = e0;
	v->e[1] = e1;
	v->e[2] = e2;
}

double	v3d_x(
	const t_v3d *v)
{
	return (v->e[0]);
}

double	v3d_y(
	const t_v3d *v)
{
	return (v->e[1]);
}

double	v3d_z(
	const t_v3d *v)
{
	return (v->e[2]);
}
