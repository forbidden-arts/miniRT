/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:09:04 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/01 13:58:42 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "stdio.h"

static void	print_lights(t_scene *scene)
{
	int	i;

	printf("**PRINT LIGHT DATA**\n\n");
	printf("lights amount: %d\n\n", scene->n_lights);
	i = -1;
	while (++i < scene->n_lights)
	{
		printf("LIGHT[%d]:\tlocation: ", i);
		print_v3d_data(&scene->lights[i].location);
		printf("\tcolor: ");
		print_v3d_data(&scene->lights[i].color);
		printf("\tintensity: %f\n", scene->lights[i].intensity);
	}
	printf("\n");
	printf("**END OF LIGHT DATA**\n\n");
}

static void	print_cameras(t_scene *scene)
{
	int	i;

	printf("**PRINT CAMERA DATA**\n\n");
	printf("cameras amount: %d\n\n", scene->n_cameras);
	i = -1;
	while (++i < scene->n_cameras)
	{
		printf("CAM[%d]:\tlocation: ", i);
		print_v3d_data(&scene->cameras[i].location);
		printf("\tdirection: ");
		print_v3d_data(&scene->cameras[i].direction);
		printf("\tFOV: %d\n", scene->cameras[i].field_of_view);
	}
	printf("\n");
	printf("**END OF CAMERA DATA**\n\n");
}

static void	print_ambient(t_ambient *ambient)
{
	printf("**PRINT AMBIENT DATA**\n\n");
	printf("intensity: %f\n", ambient->intensity);
	printf("color: ");
	print_v3d_data(&ambient->color);
	printf("\n\n**END OF AMBIENT DATA**\n\n");
}

void	print_scene_data(t_scene *scene)
{
	printf("**PRINT SCENE DATA**\n\n");
	print_ambient(&scene->ambient);
	print_cameras(scene);
	print_lights(scene);
	print_object_data(scene);
	printf("**END OF SCENE DATA**\n\n");
}
