/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:15:42 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/01 13:56:59 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "v3d.h"
#include <stdio.h>

void	print_v3d_data(t_v3d *v3d)
{
	printf("e[0]: %f, e[1]: %f, e[2]: %f ", v3d->e[0], v3d->e[1], v3d->e[2]);
}

static void	print_sphere_data(t_object *object)
{
	printf("\t\ttype: SPHERE\n");
	printf("\t\tpoint: ");
	print_v3d_data(&object->point);
	printf("\n\t\tradius: %f\n", object->radius);
	printf("\t\tcolor: ");
	print_v3d_data(&object->color);
	printf("\n");
}

static void	print_plane_data(t_object *object)
{
	printf("\t\ttype: PLANE\n");
	printf("\t\tpoint: ");
	print_v3d_data(&object->point);
	printf("\n\t\taxis: ");
	print_v3d_data(&object->axis);
	printf("\n\t\tcolor: ");
	print_v3d_data(&object->color);
	printf("\n");
}

static void	print_cylinder_data(t_object *object)
{
	printf("\t\ttype: CYLINDER\n");
	printf("\t\tpoint: ");
	print_v3d_data(&object->point);
	printf("\n\t\taxis: ");
	print_v3d_data(&object->axis);
	printf("\n\t\tradius: %f, height: %f\n", object->radius, object->height);
	printf("\t\tcolor: ");
	print_v3d_data(&object->color);
	printf("\n");
}

void	print_object_data(t_scene *scene)
{
	int	i;

	printf("PRINT OBJECT DATA\n\n");
	printf("objects amount: %d\n\n", scene->n_objects);
	i = -1;
	while (++i < scene->n_objects)
	{
		printf("\tOBJECT[%d]:\n", i);
		if (scene->objects[i].type == SPHERE)
			print_sphere_data(&scene->objects[i]);
		else if (scene->objects[i].type == CYLINDER)
			print_cylinder_data(&scene->objects[i]);
		else if (scene->objects[i].type == PLANE)
			print_plane_data(&scene->objects[i]);
		printf("\n");
	}
	printf("\n");
	printf("END OF OBJECT DATA\n\n");
}
