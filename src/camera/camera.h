/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:31:43 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/10 16:29:50 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# define DEG_TO_RAD 0.008726646259971647737

# include "scene.h"

void	init_camera(t_camera *camera);
t_ray	create_ray(t_camera *cam, const t_v2d pixel);

#endif
