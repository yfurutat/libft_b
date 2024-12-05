/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:16:31 by yuske             #+#    #+#             */
/*   Updated: 2023/03/30 23:14:21 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//19L
/**
 * @brief 
 * 
 * @param str1 
 * @param str2 
 * @param n_cmp 
 * @return int 
 */
int	ft_strncmp(const char *str1, const char *str2, size_t n_cmp)
{
	const unsigned char	*str1_u;
	const unsigned char	*str2_u;
	int					diff;
	size_t				i;

	str1_u = (const unsigned char *)str1;
	str2_u = (const unsigned char *)str2;
	diff = 0;
	i = 0;
	while (i < n_cmp)
	{
		if (str1_u[i] == '\0' || str2_u[i] == '\0' || str1_u[i] != str2_u[i])
		{
			diff = str1_u[i] - str2_u[i];
			break ;
		}
		i += 1;
	}
	return (diff);
}

#include <stddef.h>

bool	_chars_differ(const char chr1, const char chr2)
{
	return ((unsigned char)chr1 != (unsigned char)chr2);
}

bool	_is_end_of_str_at(const char *str, size_t i)
{
	return (str[i] == '\0');
}

int	ft_strncmp(const char *str1, const char *str2, size_t num_cmp)
{
	size_t	i;

	if (num_cmp == 0)
		return (0);
	i = 0;
	while (i < num_cmp)
	{
		if (_chars_differ(str1[i], str2[i]))
			break ;
		if (_is_end_of_str_at(str1, i) || _is_end_of_str_at(str2, i))
			break ;
		i += 1;
	}
	if (i < num_cmp)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}

//8L
// int	ft_strncmp(const char *str_a, const char *str_b, size_t n_cmp)
// {
// 	while (n_cmp-- > 0)
// 	{
// 		if (*str_a == '\0' || *str_b == '\0' || *str_a != *str_b)
// 			return ((unsigned char)*str_a - (unsigned char)*str_b);
// 		str_a++;
// 		str_b++;
// 	}
// 	return (0);
// }
