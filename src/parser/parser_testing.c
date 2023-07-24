/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_testing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:27:34 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/24 10:55:43 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "v3d.h"
#include "object.h"
#include <stdio.h>

/*	REMOVE THIS FILE WHEN FINISHING PROGRAM!	*/

static void	print_v3d_data(t_v3d *v3d)
{
	printf("X: %f\tY: %f\tZ: %f", v3d->x, v3d->y, v3d->z);
}

static void	print_camera_data(t_list **camera_lst)
{
	int			i;
	t_list		*lst_node;
	t_object	*camera;

	i = 0;
	printf("CAMERA DATA:\n");
	lst_node = *camera_lst;
	while (lst_node != NULL)
	{
		camera = lst_node->content;
		printf("\tCAMERA[%i]: ", i);
		printf("\tcoordinate: ");
		print_v3d_data(&camera->point);
		printf(",\t3d normalized vector: ");
		print_v3d_data(&camera->normalized);
		printf(",\t fov: %d\n", camera->field_of_view);
		lst_node = lst_node->next;
		i++;
	}
	printf("\n");
}

static void	print_light_data(t_list **light_lst)
{
	int			i;
	t_list		*lst_node;
	t_object	*light;

	i = 0;
	printf("LIGHT DATA:\n");
	lst_node = *light_lst;
	while (lst_node != NULL)
	{
		light = lst_node->content;
		printf("\tLIGHT[%i]: ", i);
		printf("\tcoordinate: ");
		print_v3d_data(&light->point);
		printf(",\tlight brighteness ratio: %f", light->intensity);
		printf(",\tcolor: %d\n", light->color);
		lst_node = lst_node->next;
		i++;
	}
	printf("\n");
}

static void	print_object_data(t_list **lst)
{
	int			i;
	t_list		*lst_node;
	t_object	*object;

	i = 0;
	printf("OBJECT DATA:\n");
	lst_node = *lst;
	while (lst_node != NULL)
	{
		object = lst_node->content;
		printf("\tOBJECT[%i]: ", i);
		printf("\ttype: %d", object->type);
		printf("\tcoordinate: ");
		print_v3d_data(&object->point);
		printf(",\t3d normalized vector: ");
		print_v3d_data(&object->normalized);
		printf("\tradius: %f", object->radius);
		printf(",\tcolor: %d\n", object->color);
		lst_node = lst_node->next;
		i++;
	}
	printf("\n");
}

/*	This function is used to print out the result of the scene data.
	Used to check that parsing was successful.*/
void	print_parser_results(t_scene *scene)
{
	printf("PRINTING SCENE DATA:\n\n");
	printf("AMBIENT DATA:\tintensity: %f\tcolor: %d\n\n,",
		scene->ambient_intensity, scene->ambient_color);
	print_camera_data(&scene->cameras);
	print_light_data(&scene->lights);
	print_object_data(&scene->objects);
	printf("\n");
}
