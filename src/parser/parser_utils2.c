/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:44:28 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/24 11:08:31 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "object.h"
#include "scene.h"
#include "globals.h"

/*	This function handles the creation of a new object and adding it to
	to end of the object linked list. Will return TRUE if successful. */
BOOL	create_object_and_add_to_lst_end(t_list **lst)
{
	t_object	*new_object;
	t_list		*new_node;

	new_object = ft_calloc(1, sizeof(t_object));
	if (new_object == NULL)
		return (FALSE);
	new_node = ft_lstnew(new_object);
	if (new_node == NULL)
	{
		free(new_object);
		return (FALSE);
	}
	ft_lstadd_back(lst, new_node);
	return (TRUE);
}

/*	This function simply checks that the color data is an integer
	and that it is in the bounds [0,255].
	If an error is encountered goes to error_exit().
	
	Used inside color_checkset.*/
void	check_color(char *str, t_parser *f)
{
	int	result;

	if (!ft_isinteger(str))
		error_exit("Not a valid color integer", f);
	result = ft_atoi(str);
	if (result < 0 || result > 255)
		error_exit("Color value not in bounds [0, 255]", f);
}
