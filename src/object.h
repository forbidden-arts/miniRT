/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:13:32 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/26 13:48:44 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "libft.h"
# include "v3d.h"

/* NOTES FOR US:

We can add or take away from this, I'm brainstorming, along with GPT, on all
of the different data "points" needed for different geometries.

*** Axis is a weird one... Imagine we want to create a cone that's lopsided,
or turn a cube into a parallelagram. It won't be needed if we stick to the
mandatory, but thought I'd toss it in.

*/

/*	OBJECT TYPES (not required for lights or cameras because they
	are in their own linked lists):
	0. SPHERE
	1. CYLINDER
	2. PLANE
*/
typedef enum e_object_type
{
	SPHERE,
	CYLINDER,
	PLANE
}	t_object_type;

typedef struct s_object
{
	int		type;
	t_v3d	point;
	t_v3d	normalized;
	t_v3d	axis;
	t_v3d	color;
	double	radius;
	double	height;
	double	width;
	double	intensity;
	int		field_of_view;
	BOOL	is_light;
	BOOL	is_camera;
}	t_object;

#endif