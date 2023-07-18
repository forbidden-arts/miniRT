/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:56:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/18 12:36:32 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "v3d.h"

typedef struct s_sphere
{
	t_v3d	point;
	double	radius;
}	t_sphere;

t_sphere	*create_sphere(t_v3d center, double radius);

#endif
