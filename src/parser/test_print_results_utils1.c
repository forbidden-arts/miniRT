/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_results_utils1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:42:22 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 13:22:08 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "object.h"

#include <stdio.h>

void	print_sphere_data(t_object *sphere)
{
	printf("\ttype: SPHERE");
	printf("\tcoordinate: ");
	print_v3d_data(&sphere->point);
	printf("\tradius: %f", sphere->radius);
	printf("\tcolor: %d\n", sphere->color);
}

void	print_cylinder_data(t_object *cylinder)
{
	printf("\ttype: CYLINDER");
	printf("\tcoordinate: ");
	print_v3d_data(&cylinder->point);
	printf(",\taxis: ");
	print_v3d_data(&cylinder->axis);
	printf("\tradius: %f", cylinder->radius);
	printf("\theight: %f", cylinder->height);
	printf("\tcolor: %d\n", cylinder->color);
}

void	print_plane_data(t_object *plane)
{
	printf("\ttype: CYLINDER");
	printf("\tcoordinate: ");
	print_v3d_data(&plane->point);
	printf(",\taxis: ");
	print_v3d_data(&plane->axis);
	printf("\tcolor: %d\n", plane->color);
}
