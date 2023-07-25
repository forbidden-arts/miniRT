/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:05:00 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/24 12:34:06 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3d.h"

double	get_dot(t_v3d a, t_v3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_v3d	get_cross(t_v3d a, t_v3d b)
{
	t_v3d	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_v3d	vector_add(t_v3d a, t_v3d b)
{
	t_v3d	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

t_v3d	vector_sub(t_v3d a, t_v3d b)
{
	t_v3d	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_v3d	vector_multiply_by_t(t_v3d a, double t)
{
	t_v3d	result;

	result.x = a.x * t;
	result.y = a.x * t;
	result.z = a.z * t;
	return (result);
}
