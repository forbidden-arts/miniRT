/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:22:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/28 12:26:07 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V3D_H
# define V3D_H

# include "libft.h"

typedef struct s_v3d
{
	double	x;
	double	y;
	double	z;
}	t_v3d;

t_v3d	init_v3d(double x, double y, double z);
t_v3d	normalize_vector(t_v3d input);
double	vector_len(t_v3d input);
void	swap_double(double *a, double *b);
BOOL	solve_quadratic(t_v3d params, double *r0, double *r1);

double	get_dot(t_v3d a, t_v3d b);
t_v3d	get_cross(t_v3d a, t_v3d b);
t_v3d	vector_add(t_v3d a, t_v3d b);
t_v3d	vector_sub(t_v3d a, t_v3d b);
t_v3d	vector_multiply_by_t(t_v3d a, double t);

#endif
