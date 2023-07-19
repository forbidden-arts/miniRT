/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:26 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/19 15:06:02 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"

/*	This function simply frees everything allocated for the scene. Used
	if there is a parsing error while reading the file or when closing the
	program. */
int	scene_free_elems(t_scene *scene)
{
	ft_lstclear(scene->objects, free);
	ft_lstclear(scene->lights, free);
	ft_lstclear(scene->cameras, free);
	return (0);
}
