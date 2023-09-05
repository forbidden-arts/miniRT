/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:09:43 by ssalmi            #+#    #+#             */
/*   Updated: 2023/09/05 11:10:04 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "scene.h"

#include <stdio.h>

/*	Function to initiate all mlx data to NULL	*/
static void	init_mlx_data(
	t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.img = NULL;
	data->img.addr = NULL;
}

/*	Function to initiate all data variables to NULL
	Call in the beginning of program	*/
void	init_data(
	t_data *data)
{
	init_scene(&data->scene);
	init_mlx_data(data);
}

/*	This function frees everything allocated for data and exits with
	the given exit code.*/
void	exit_minirt(
	t_data *data,
	int exit_code)
{
	printf("\nClosing program\n");
	free_scene(&data->scene);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(exit_code);
}
