/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:50:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/17 12:54:36 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "v3d.h"

t_v3d	init_v3d(double x, double y, double z)
{
	t_v3d	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
