/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:25:49 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/22 14:54:46 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "data.h"

# define KEY_ESC 53

int	press_close(
		t_data *data);
int	get_key(
		int key_code,
		t_data *data);

#endif
