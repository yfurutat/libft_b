/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:39:00 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 04:46:53 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//14L
/**
 * @brief 
 * 
 * @param str 
 * @return char* 
 */
char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	dup = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i += 1;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(str) + 1;
	dup = malloc(sizeof(char) * len);
	if (dup != NULL)
		ft_strlcpy(dup, str, len);
	return (dup);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = malloc(sizeof(char) * n);
	if (dup != NULL)
		ft_strlcpy(dup, str, n);
	return (dup);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = malloc(sizeof(char) * n);
	if (dup != NULL)
		dup = ft_strlcpy(dup, str, n);
	return (dup);
}

char	*ft_strdup(const char *str)
{
	return (ft_strndup(str, ft_strlen(str)));
}
