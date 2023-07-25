/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:51:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 11:13:06 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_data.h"
#include "scene.h"
#include "stdio.h"

#define KEY_ESC 53

int	get_key(int key_code, t_mlx *data)
{
	if (key_code == KEY_ESC)
		return (press_close(data));
	return (0);
}

static void	end_program(void)
{
	exit (0);
}

int	press_close(t_mlx *data)
{
	(void)data;
	printf("Closing program!\n");
	end_program();
	return (0);
}
