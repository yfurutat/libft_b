/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:12:54 by yuske             #+#    #+#             */
/*   Updated: 2025/06/29 21:36:48 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h> // malloc, free

static size_t	_count_words(const char *str, char delim);
static size_t	_proc_words(char const *str, char delim, \
	char **split_words, size_t num_words);
static bool		_free_null_dptr(char ***split_words);

char	**ft_split(char const *str, char delim)
{
	char	**split_words;
	size_t	num_words;

	if (str == NULL || *str == '\0')
		return (NULL);
	num_words = _count_words(str, delim);
	split_words = (char **)malloc((num_words + 1) * sizeof(char *));
	if (split_words == NULL)
		return (NULL);
	if (_proc_words(str, delim, split_words, num_words) != num_words)
		_free_null_dptr(&split_words);
	return (split_words);
}

static size_t	_count_words(const char *str, char delim)
{
	size_t	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		if (*str != delim)
		{
			cnt++;
			while (*str != delim && *str != '\0')
				str++;
		}
		else
			str++;
	}
	return (cnt);
}

static size_t	_proc_words(char const *str, char delim, \
	char **split_words, size_t num_words)
{
	size_t	start;
	size_t	len;
	size_t	i;

	start = 0;
	i = 0;
	while (i < num_words && str[start] != '\0')
	{
		if (str[start] != delim)
		{
			len = 0;
			while (str[start + len] != delim && str[start + len] != '\0')
				len++;
			split_words[i] = ft_substr(str, start, len);
			if (split_words[i] == NULL)
				return (i);
			i++;
			start += len;
		}
		else
			start++;
	}
	split_words[i] = NULL;
	return (i);
}

static bool	_free_null_dptr(char ***split_words)
{
	size_t	i;

	if (split_words && *split_words)
	{
		i = 0;
		while ((*split_words)[i])
		{
			free((*split_words)[i]);
			(*split_words)[i] = NULL;
			i++;
		}
		free(*split_words);
		*split_words = NULL;
		return (true);
	}
	return (false);
}



// [leaks] [crash】 split: str==NULL で leaks, malloc) 失敗時に segv
// typedef struct s_split_utility
// {
// 	char	p;
// 	size_t	n;
// 	size_t	i;
// 	size_t	start;
// 	size_t	len;
// }	t_util;
	// size_t	end;

// typedef struct s_split_utility
// {
// 	char	p;
// 	size_t	n;
// 	size_t	i;
// 	size_t	len;
// }	t_util;

// static t_util	*init(t_util *sb);
// // static size_t	word_cnt(const char *str, t_util *sb);
// static size_t	word_cnt(const char *str, char c);
// static char		**word_proc(char const *str, char **split, t_util *sb);
// static char		**free_f_all(char **split, t_util *sb);

// // //16-20L
// char	**ft_split(char const *str, char c)
// {
// 	t_util	sb;
// 	char	**split;

// 	if (str == NULL || c < 0)
// 		return (NULL);
// 	split = NULL;
// 	init(&sb);
// 	sb.p = c;
// 	sb.n = word_cnt(str, c);
// 	split = (char **)malloc((sb.n + 1) * sizeof(char *));
// 	if (split != NULL)
// 		split = word_proc(str, split, &sb);
// 	return (split);
// }
// 			// sb->words[sb->n + 1] = NULL;

// static t_util	*init(t_util *sb)
// {
// 	sb->p = '\0';
// 	sb->n = 0;
// 	sb->i = 0;
// 	sb->start = 0;
// 	sb->len = 0;
// 	return (sb);
// }
	// sb->end = 0;

// static t_util	*init(t_util *sb)
// {
// 	sb->p = '\0';
// 	sb->n = 0;
// 	sb->i = 0;
// 	sb->len = 0;
// 	return (sb);
// }

//11L
// static size_t	word_cnt(const char *str, t_util *sb)
// static size_t	word_cnt(const char *str, char c)
// {
// 	size_t	cnt;

// 	cnt = 0;
// 	while (*str != '\0')
// 	{
// 		if (*str != c)
// 		{
// 			cnt += 1;
// 			while (*str != c && *str != '\0')
// 				str += 1;
// 		}
// 		str += 1;
// 	}
// 	return (cnt);
// }

//18-20L
// static char	**word_proc(char const *str, char **split, t_util *sb)
// {
// 	// sb->start = 0;
// 	// sb->end = 0;
// 	while (sb->i < sb->n && str[sb->start] != '\0')
// 	{
// 		if (str[sb->start] != sb->p)
// 		{
// 			sb->end = sb->start;
// 			while (str[sb->end] != sb->p && str[sb->end] != '\0')
// 				sb->end += 1;
// 			split[sb->i] = ft_strndup(&str[sb->start], sb->end - sb->start);
// 			if (free_f_all(split, sb) == NULL)
// 				return (split);
// 			sb->i += 1;
// 			sb->start = sb->end;
// 		}
// 		else
// 			sb->start += 1;
// 	}
// 	split[sb->i] = NULL;
// 	return (split);
// }
			// printf("1. %zd %zd\n", sb->start, sb->end);
			// printf("2. %zd %zd\n", sb->start, sb->end);

//20L
// static char	**word_proc(char const *str, char **split, t_util *sb)
// {
// 	sb->start = 0;
// 	while (sb->i < sb->n && str[sb->start] != '\0')
// 	{
// 		if (str[sb->start] != sb->p)
// 		{
// 			sb->len = 0;
// 			while (str[sb->start + sb->len] != sb->p \
// 				&& str[sb->start + sb->len] != '\0')
// 				sb->len += 1;
// 			split[sb->i] = ft_substr(str, start, sb->len);
// 			if (free_f_all(split, sb) == NULL)
// 				return (split);
// 			sb->i += 1;
// 			sb->start += sb->len;
// 		}
// 		else
// 			sb->start += 1;
// 	}
// 	split[sb->i] = NULL;
// 	return (split);
// }

//20L
// static char	**word_proc(char const *str, char **split, t_util *sb)
// {
// 	sb->end = 0;
// 	while (*str == sb->p)
// 		str += 1;
// 	while (str[sb->end] && sb->i < sb->n)
// 	{
// 		if (str[sb->end] != sb->p)
// 		{
// 			sb->start = sb->end;
// 			while (str[sb->end] != sb->p && str[sb->end])
// 				sb->end += 1;
// 			split[sb->i] = ft_strndup(&str[sb->start], sb->end - sb->start);
// 			if (free_f_all(split, sb) == NULL)
// 				return (split);
// 			sb->i += 1;
// 		}
// 		else
// 			sb->end += 1;
// 	}
// 	split[sb->i] = NULL;
// 	return (split);
// }
			// split[sb->i] = ft_substr(str, sb->start, sb->end - sb->start);

//18L RECURSION
// static char	**word_proc(const char *str, char **split, t_util *sb)
// {
// 	if (*str == '\0' || sb->i >= sb->n)
// 	{
// 		split[sb->i] = NULL;
// 		return (split);
// 	}
// 	while (*str == sb->p && *str != '\0')
// 		str += 1;
// 	sb->len = 0;
// 	while (str[sb->len] != sb->p && str[sb->len] != '\0')
// 		sb->len += 1;
// 	if (sb->len > 0 && sb->i < sb->n)
// 	{
// 		split[sb->i] = ft_strndup(str, sb->len);
// 		if (free_f_all(split, sb) == NULL)
// 			return (split);
// 		sb->i += 1;
// 	}
// 	return (word_proc(str + sb->len, split, sb));
// }
	// return (word_proc(str + len + (str[len] == sb->p), split, sb));

// //10L
// static char	**free_f_all(char **split, t_util *sb)
// {
// 	if (split[sb->i] == NULL)
// 	{
// 		while (sb->i > 0)
// 		{
// 			sb->i -= 1;
// 			free(split[sb->i]);
// 			split[sb->i] = NULL;
// 		}
// 		free(split);
// 		split = NULL;
// 	}
// 	return (split);
// }
