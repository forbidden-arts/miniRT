/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:14:40 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/16 14:38:48 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "ray.h"
#include "shapes.h"

BOOL	get_closest_t(
	double t0,
	double t1,
	double *impact_time)
{
	if (t0 < EPSILON && t1 < EPSILON)
		return (FALSE);
	if (t1 > EPSILON)
		*impact_time = t1;
	else
		*impact_time = t0;
	return (TRUE);
}
