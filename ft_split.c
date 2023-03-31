/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:12:54 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 05:15:48 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_split_utility
{
	char	**words;
	char	p;
	size_t	n;
	size_t	i;
}	t_util;

static void	initializer(t_util *util);
static void	counter(const char *str, t_util *util);
static void	processor(char const *str, t_util *util);
static void	free_f_all(t_util *util);

// //16-20L
char	**ft_split(char const *str, char c)
{
	t_util	*util;
	char	**split;

	split = NULL;
	util = ft_calloc(1, sizeof(t_util));
	if (str != NULL && util != NULL)
	{
		initializer(util);
		util->p = c;
		counter(str, util);
		util->words = ft_calloc((util->n + 1), sizeof(char *));
		if (util->words != NULL)
		{
			split = util->words;
			processor(str, util);
		}
		free(util);
	}
	return (split);
}
			// util->words[util->n + 1] = NULL;

static void	initializer(t_util *util)
{
	util->words = NULL;
	util->p = '\0';
	util->n = 0;
	util->i = 0;
}

//11L
static void	counter(const char *str, t_util *util)
{
	util->n = 0;
	while (*str)
	{
		if (*str != util->p)
		{
			util->n += 1;
			while (*str != util->p && *str)
				str += 1;
		}
		str += 1;
	}
}

//19-21L
static void	processor(char const *str, t_util *util)
{
	size_t	start;
	size_t	j;

	j = 0;
	while (*str == util->p)
		str += 1;
	while (str[j] && util->i < util->n)
	{
		if (str[j] != util->p)
		{
			start = j;
			while (str[j] != util->p && str[j])
				j += 1;
			util->words[util->i] = ft_substr(str, start, j - start);
			free_f_all(util);
			util->i += 1;
		}
		else
			j += 1;
	}
	util->words[util->i] = NULL;
}

//10L
static void	free_f_all(t_util *util)
{
	if (!util->words[util->i])
	{
		while (util->i > 0)
		{
			free(util->words[util->i]);
			util->i -= 1;
		}
		free(util->words);
		util->words = NULL;
	}
}
