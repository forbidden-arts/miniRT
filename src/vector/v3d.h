/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:22:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/17 14:58:28 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V3D_H
# define V3D_H

typedef struct s_v3d
{
	double	x;
	double	y;
	double	z;
}	t_v3d;

t_v3d	init_v3d(double x, double y, double z);

#endif
