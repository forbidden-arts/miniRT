/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:09:04 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/23 13:30:31 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stdio.h"

static void	print_lights(
	t_scene *scene)
{
	int	i;

	printf("\t\t**PRINT LIGHT DATA**\n\n");
	printf("\tlights amount: %d\n\n", scene->n_lights);
	i = -1;
	while (++i < scene->n_lights)
	{
		printf("\tLIGHT[%d]:\n", i);
		printf("\t\tlocation: ");
		print_v3d_data(&scene->lights[i].location);
		printf("\n\t\tintensity: %f", scene->lights[i].intensity);
		printf("\n\t\tcolor: ");
		print_v3d_data(&scene->lights[i].color);
		printf("\n\n");
	}
	printf("\n");
}

static void	print_cameras(
	t_scene *scene)
{
	int	i;

	printf("\t\t**PRINT CAMERA DATA**\n\n");
	printf("\tcameras amount: %d\n\n", scene->n_cameras);
	i = -1;
	while (++i < scene->n_cameras)
	{
		printf("\tCAM[%d]:\n", i);
		printf("\t\tlocation: ");
		print_v3d_data(&scene->cameras[i].location);
		printf("\n\t\tdirection: ");
		print_v3d_data(&scene->cameras[i].direction);
		printf("\n\t\tFOV: %f\n\n", scene->cameras[i].field_of_view);
	}
	printf("\n");
}

static void	print_ambient(
	t_ambient *ambient)
{
	printf("\t\t**PRINT AMBIENT DATA**\n\n");
	printf("\tintensity: %f\n", ambient->intensity);
	printf("\tcolor: ");
	print_v3d_data(&ambient->color);
	printf("\n\n");
}

void	print_scene_data(
	t_scene *scene)
{
	printf("\n\t*****************PRINT SCENE DATA*****************\n\n");
	print_ambient(&scene->ambient);
	print_cameras(scene);
	print_lights(scene);
	print_object_data(scene);
	printf("\t*****************END OF SCENE DATA*****************\n\n");
}
