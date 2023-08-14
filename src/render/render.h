/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:50:53 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/14 15:55:00 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "data.h"
# include "scene.h"
# include "v3d.h"
# include "ray.h"

# define MAX_DEPTH 1

/* Point is where on an object the ray impacts in a 3D space.
*  Normal the direction relative to the "center" of the object. */
typedef struct s_impact
{
	int			object_type;
	double		distance;
	t_v3d		color;
	t_object	*object;
	t_v3d		point;
	t_v3d		normal;
}	t_impact;

void	render_image(t_data *data);

void	copy_impact_data(t_impact *impact_src, t_impact *impact_dst);
BOOL	get_ray_hit(t_scene *scene, t_impact *impact, t_ray *ray);

#endif
