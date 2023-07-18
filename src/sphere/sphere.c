/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:56:47 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/18 13:07:16 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sphere.h"

t_sphere	*create_sphere(t_v3d center, double radius)
{
	t_sphere	*sphere;

	if (!radius)
		return (NULL);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->point = center;
	sphere->radius = radius;
	return (sphere);
}
