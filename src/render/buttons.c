/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:51:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 12:12:42 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "keys.h"

#include <stdio.h>

int	get_key(int key_code, t_data *data)
{
	if (key_code == KEY_ESC)
		return (press_close(data));
	return (0);
}

static void	end_program(void)
{
	exit (0);
}

int	press_close(t_data *data)
{
	(void)data;
	printf("Closing program!\n");
	end_program();
	return (0);
}
