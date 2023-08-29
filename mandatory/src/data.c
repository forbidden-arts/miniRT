/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:09:43 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/29 13:32:06 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "scene.h"

static void	free_mlx_data(
	t_data *data)
{
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->win_ptr)
		free(data->win_ptr);
	if (data->img.img)
		free(data->img.img);
	if (data->img.addr)
		free(data->img.addr);
}

void	free_data(
	t_data *data)
{
	free_scene(&data->scene);
	free_mlx_data(data);
}

static void	init_mlx_data(
	t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.img = NULL;
	data->img.addr = NULL;
}

void	init_data(
	t_data *data)
{
	init_scene(&data->scene);
	init_mlx_data(data);
}

void	exit_minirt(
	t_data *data,
	int exit_code)
{
	free_data(data);
	exit(exit_code);
}
