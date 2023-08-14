/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:50:53 by ssalmi            #+#    #+#             */
/*   Updated: 2023/08/14 16:08:10 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "data.h"
# include "scene.h"
# include "v3d.h"
# include "ray.h"

# define MAX_DEPTH 1

void	render_image(t_data *data);

#endif
