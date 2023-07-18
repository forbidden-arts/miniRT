/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:22:44 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/18 14:47:47 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

static int	check_file_name(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len <= 3)
		return (1);
	if (ft_strncmp(&arg[len - 3], ".rt", 3) != 0)
		return (2);
	return (0);
}

static int	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error\nGive a valid rt-file to read as an argument!\n");
		return (1);
	}
	else if (argc > 2)
	{
		printf("Error\nToo many of arguments! "
			"(Give only one rt-file as argument)\n");
		return (2);
	}
	if (check_file_name(argv[1]) != 0)
	{
		printf("Error\nInvalid argument given! "
			"(give a valid rt-file as an argument)\n");
		return (3);
	}
	return (0);
}

static int	open_file(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		perror("Error\nError when trying to open file");
	return (fd);
}

/*	This function handles the reading and parsing the file. Returns zero if
	successfull.	*/
int	file_handler(int argc, char **argv)
{
	int	fd;

	if (check_args(argc, argv) != 0)
		exit (1);
	fd = open_file(argv[1]);
	if (fd == -1)
		exit (2);
	file_parser(fd);
	return (0);
}
