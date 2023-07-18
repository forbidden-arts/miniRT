/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:18:30 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/18 12:37:31 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "v3d.h"

typedef struct s_cylinder
{
	t_v3d	point;
	t_v3d	normalized;
	double	radius;
	double	height;
}	t_cylinder;

#endif
