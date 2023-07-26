/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:56:47 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/25 15:18:31 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "sphere.h"

BOOL	*create_sphere(t_v3d center, double radius)
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
