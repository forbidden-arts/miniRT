/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:50:41 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 11:16:32 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "scene.h"
#include "object.h"
#include "globals.h"
#include <stdio.h>

/*	Talk to Dan: it would be preferable that the object type value was
	an integer (use enum) than a string, because then you don't need to
	malloc anything for the object, which in turn makes freeing the objects
	linked list in the scene a conveniant.*/
void	parse_sphere(t_parser *f)
{
	t_object	*sphere;
	double		sphere_diameter;

	f->error_part = f->line;
	if (str_array_count_strings(f->line_parts_array) != 4)
		error_exit("Incorrect amount of element data parts", f);
	if (create_object_and_add_to_lst_end(&g_data.scene.objects) == FALSE)
		error_exit("Malloc failure when creating element object", f);
	sphere = ft_lstlast(g_data.scene.objects)->content;
	sphere->type = SPHERE;
	coordinate_checkset(f->line_parts_array[1], &sphere->point, f);
	f->error_part = f->line_parts_array[2];
	object_dimension_checkset(f->line_parts_array[2], &sphere_diameter, f);
	sphere->radius = sphere_diameter / 2;
	color_checkset(f->line_parts_array[3], &sphere->color, f);
}

void	parse_cylinder(t_parser *f)
{
	t_object	*cylinder;
	double		cy_diameter;

	f->error_part = f->line;
	if (str_array_count_strings(f->line_parts_array) != 6)
		error_exit("Incorrect amount of element data parts", f);
	if (create_object_and_add_to_lst_end(&g_data.scene.objects) == FALSE)
		error_exit("Malloc failure when creating element object", f);
	cylinder = ft_lstlast(g_data.scene.objects)->content;
	cylinder->type = CYLINDER;
	coordinate_checkset(f->line_parts_array[1], &cylinder->point, f);
	three_d_normalized_vector_checkset(f->line_parts_array[2],
		&cylinder->normalized, f);
	object_dimension_checkset(f->line_parts_array[3], &cy_diameter, f);
	cylinder->radius = cy_diameter / 2;
	object_dimension_checkset(f->line_parts_array[4], &cylinder->height, f);
	color_checkset(f->line_parts_array[5], &cylinder->color, f);
}

void	parse_plane(t_parser *f)
{
	t_object	*plane;

	f->error_part = f->line;
	if (str_array_count_strings(f->line_parts_array) != 4)
		error_exit("Incorrect amount of element data parts", f);
	if (create_object_and_add_to_lst_end(&g_data.scene.objects) == FALSE)
		error_exit("Malloc failure when creating element object", f);
	plane = ft_lstlast(g_data.scene.objects)->content;
	plane->type = PLANE;
	coordinate_checkset(f->line_parts_array[1], &plane->point, f);
	three_d_normalized_vector_checkset(f->line_parts_array[2],
		&plane->normalized, f);
	color_checkset(f->line_parts_array[3], &plane->color, f);
}
