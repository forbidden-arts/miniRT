/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:51:10 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/29 13:07:11 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "keys.h"

#include <stdio.h>

int	get_key(
	int key_code,
	t_data *data)
{
	if (key_code == KEY_ESC)
		return (press_close(data));
	return (0);
}

int	press_close(
	t_data *data)
{
	exit_minirt(data, 0);
	return (0);
}
