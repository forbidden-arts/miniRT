/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalmi <ssalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:09:50 by ssalmi            #+#    #+#             */
/*   Updated: 2023/07/20 17:00:16 by ssalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

#define DELIMITERS " \t"

static char	**minirt_split_unwind(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static char	*minirt_split_create_word(char const *s, char const *delim)
{
	size_t	end;
	char	*word;

	end = 0;
	while (!ft_strchr(delim, s[end]) && s[end])
		end++;
	word = ft_substr(s, 0, end);
	if (!word)
		return (NULL);
	return (word);
}

static size_t	minirt_split_word_count(char const *s, char const *delim)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (ft_strchr(delim, *s) && *s)
			s++;
		if (*s)
			count++;
		while (!ft_strchr(delim, *s) && *s)
			s++;
	}
	return (count);
}

/*	This is a modified ft_split for splitting the lines during parsing.
	Based on dpalmer's libft's ft_split.	*/
char	**minirt_split(char const *s)
{
	char	**split;
	size_t	i;

	split = (char **)ft_calloc((minirt_split_word_count(s, DELIMITERS) + 1),
			sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (ft_strchr(DELIMITERS, *s) && *s)
			s++;
		if (*s)
		{
			split[i++] = minirt_split_create_word(s, DELIMITERS);
			if (!split[i - 1])
				return (minirt_split_unwind(split));
			while (!ft_strchr(DELIMITERS, *s) && *s)
				s++;
		}
	}
	return (split);
}
