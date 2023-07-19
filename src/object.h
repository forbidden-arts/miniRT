/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:13:32 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/18 18:45:56 by dpalmer          ###   ########.fr       */
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

typedef struct s_object
{
	char	*type;
	t_v3d	point;
	t_v3d	normalized;
	t_v3d	axis;
	int		color;
	int		radius;
	int		height;
	int		width;
	int		intensity;
	int		field_of_view;
	BOOL	is_light;
	BOOL	is_camera;
}	t_object;

#endif