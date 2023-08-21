/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:22:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/08/21 11:53:05 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V3D_H
# define V3D_H

# include "math.h"
# include "libft.h"

typedef struct s_v3d
{
	double	e[3];
}	t_v3d;

//Aliases
typedef t_v3d	t_point3;
typedef t_v3d	t_color;

//Prototypes
void	v3d_init(t_v3d *v);
void	v3d_init_with_values(t_v3d *v, double e0, double e1, double e2);
double	v3d_x(const t_v3d *v);
double	v3d_y(const t_v3d *v);
double	v3d_z(const t_v3d *v);

// double	v3d_get(const t_v3d *v, int i);
// void	v3d_set(t_v3d *v, int i, double val);
// void	swap_double(double *a, double *b);

t_v3d	v3d_negate(const t_v3d *v);
double	v3d_get_dist(const t_v3d *origin, const t_v3d *dest);

void	v3d_add_in_place(t_v3d *v, const t_v3d *other);
void	v3d_multiply_in_place(t_v3d *v, double t);
void	v3d_divide_in_place(t_v3d *v, double t);

double	v3d_length(const t_v3d *v);
double	v3d_length_squared(const t_v3d *v);
double	v3d_dot(const t_v3d *u, const t_v3d *v);
t_v3d	v3d_cross(const t_v3d *u, const t_v3d *v);
t_v3d	v3d_unit_vector(t_v3d *v);

t_v3d	v3d_add(const t_v3d *u, const t_v3d *v);
t_v3d	v3d_subtract(const t_v3d *u, const t_v3d *v);
t_v3d	v3d_multiply(const t_v3d *u, const t_v3d *v);
t_v3d	v3d_multiply_scalar(const t_v3d *v, double t);
t_v3d	v3d_divide_scalar(const t_v3d *v, double t);

BOOL	solve_quadratic(t_v3d params, double *t0, double *t1);

#endif
