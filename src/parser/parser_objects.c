/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:50:41 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/25 11:58:37 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "scene.h"
#include "object.h"

/*	Talk to Dan: it would be preferable that the object type value was
	an integer (use enum) than a string, because then you don't need to
	malloc anything for the object, which in turn makes freeing the objects
	linked list in the scene a conveniant.*/
void	parse_sphere(t_parser *f, t_scene *scene)
{
	t_object	*sphere;
	double		sphere_diameter;

	f->error_part = f->line;
	if (str_array_count_strings(f->line_parts_array) != 4)
		error_exit("Incorrect amount of element data parts", f, scene);
	if (create_object_and_add_to_lst_end(&scene->objects) == FALSE)
		error_exit("Malloc failure when creating element object", f, scene);
	sphere = ft_lstlast(scene->objects)->content;
	sphere->type = SPHERE;
	coordinate_checkset(f->line_parts_array[1], &sphere->point, f, scene);
	f->error_part = f->line_parts_array[2];
	object_dimension_checkset(f->line_parts_array[2], &sphere_diameter,
		f, scene);
	sphere->radius = sphere_diameter / 2;
	color_checkset(f->line_parts_array[3], &sphere->color, f, scene);
}

void	parse_cylinder(t_parser *f, t_scene *scene)
{
	t_object	*cylinder;
	double		cy_diameter;

	f->error_part = f->line;
	if (str_array_count_strings(f->line_parts_array) != 6)
		error_exit("Incorrect amount of element data parts", f, scene);
	if (create_object_and_add_to_lst_end(&scene->objects) == FALSE)
		error_exit("Malloc failure when creating element object", f, scene);
	cylinder = ft_lstlast(scene->objects)->content;
	cylinder->type = CYLINDER;
	coordinate_checkset(f->line_parts_array[1], &cylinder->point, f, scene);
	three_d_normalized_vector_checkset(f->line_parts_array[2],
		&cylinder->normalized, f, scene);
	object_dimension_checkset(f->line_parts_array[3], &cy_diameter, f, scene);
	cylinder->radius = cy_diameter / 2;
	object_dimension_checkset(f->line_parts_array[4], &cylinder->height,
		f, scene);
	color_checkset(f->line_parts_array[5], &cylinder->color, f, scene);
}

void	parse_plane(t_parser *f, t_scene *scene)
{
	t_object	*plane;

	f->error_part = f->line;
	if (str_array_count_strings(f->line_parts_array) != 4)
		error_exit("Incorrect amount of element data parts", f, scene);
	if (create_object_and_add_to_lst_end(&scene->objects) == FALSE)
		error_exit("Malloc failure when creating element object", f, scene);
	plane = ft_lstlast(scene->objects)->content;
	plane->type = PLANE;
	coordinate_checkset(f->line_parts_array[1], &plane->point, f, scene);
	three_d_normalized_vector_checkset(f->line_parts_array[2],
		&plane->normalized, f, scene);
	color_checkset(f->line_parts_array[3], &plane->color, f, scene);
}
