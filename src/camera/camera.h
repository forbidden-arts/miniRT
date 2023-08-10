/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:31:43 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/10 09:10:26 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# define DEG2RAD 0.008726646259971647737

# include "scene.h"

void	init_camera(t_camera *camera);
t_ray	create_ray(const t_camera *cam, const t_v2d pixel);

#endif