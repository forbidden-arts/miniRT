/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:22:44 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/20 11:52:03 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/* Checking to see if the file ends in '.rt' */
static BOOL	check_file_name(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (len <= 3)
		return (FALSE);
	if (ft_strncmp(&arg[len - 3], ".rt", 3) != 0)
		return (FALSE);
	return (FALSE);
}

static BOOL	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		perror("Error\nGive a valid rt-file to read as an argument!\n");
		return (FALSE);
	}
	else if (argc > 2)
	{
		perror("Error\nToo many of arguments! "
			"(Give only one rt-file as argument)\n");
		return (FALSE);
	}
	if (check_file_name(argv[1]) != 0)
	{
		perror("Error\nInvalid argument given! "
			"(give a valid rt-file as an argument)\n");
		return (FALSE);
	}
	return (TRUE);
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
BOOL	file_handler(int argc, char **argv)
{
	int	fd;

	if (check_args(argc, argv) != 0)
		return (FALSE);
	fd = open_file(argv[1]);
	if (fd == -1)
		return (FALSE);
	return (file_parser(fd));
}
