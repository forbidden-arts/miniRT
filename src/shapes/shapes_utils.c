/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:29:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/16 17:35:26 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"

t_v3d	get_object_normal(t_object *object, t_v3d impact)
{
	t_v3d	normal;

	if (object->type == SPHERE)
		normal = v3d_subtract(&impact, &object->point);
	v3d_unit_vector(&normal);
	return (normal);
}
