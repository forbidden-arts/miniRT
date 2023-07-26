/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:09:43 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/26 11:10:29 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "scene.h"

/*	Free everything to do with mlx	*/
static void	free_mlx_data(t_data *data)
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

/*	Free everything malloced for program	*/
void	free_data(t_data *data)
{
	free_scene(&data->scene);
	free_mlx_data(data);
}

/*	Function to initiate all mlx data to NULL	*/
static void	init_mlx_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img.img = NULL;
	data->img.addr = NULL;
}

/*	Function to initiate all data variables to NULL	
	Call in the beginning of program	*/
void	init_data(t_data *data)
{
	init_scene(&data->scene);
	init_mlx_data(data);
}
