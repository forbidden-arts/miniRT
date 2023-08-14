/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:31:43 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/14 16:09:48 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# define DEG2RAD 0.008726646259971647737

# include "scene.h"
# include "ray.h"

void	init_camera(t_camera *camera);
t_ray	create_ray(t_camera *cam, const t_v2d pixel);

#endif
