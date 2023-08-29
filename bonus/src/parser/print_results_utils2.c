/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:42:36 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/23 12:52:17 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "v3d.h"
#include <stdio.h>

void	print_cone_data(
	t_object *object)
{
	printf("\t\ttype: CONE\n");
	printf("\t\tpoint: ");
	print_v3d_data(&object->point);
	printf("\n\t\taxis: ");
	print_v3d_data(&object->axis);
	printf("\n\t\tradius: %f, height: %f\n", object->radius, object->height);
	printf("\t\tcolor: ");
	print_v3d_data(&object->color);
	printf("\n");
}
