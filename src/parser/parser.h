/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:10:14 by dpalmer           #+#    #+#             */
/*   Updated: 2023/07/26 12:34:36 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

// parser_utils1.c
BOOL	return_err(char *error_msg, char *optional_str_to_free);
BOOL	free_str_and_return_false(char *str);
BOOL	ft_isinteger(char *s);
BOOL	color_part_checkset(char *color_data, double *target_data);
BOOL	check_char_amount_in_str(char *str, char c, int correct_amount);

// parser_utils2.c
BOOL	coordinate_part_checkset(char *str, double *target_data);
BOOL	axis_part_checkset(char *str, double *target_data);
BOOL	dimension_checkset(char *str, double *target_data);

// parser_checksets.c
BOOL	color_checkset(char *str, t_v3d *target_data);
BOOL	coordinate_checkset(char *str, t_v3d *target_data);
BOOL	axis_checkset(char *str, t_v3d *target_data);
BOOL	brightness_ratio_checkset(char *str, double *target_data);
BOOL	object_dimension_checkset(char *str, double *target_data);

// parser_double_utils.c
BOOL	ft_isdouble_simple(const char *s);
double	ft_atof_simple(const char *s);

#endif
