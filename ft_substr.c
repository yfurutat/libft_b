/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:59:02 by yuske             #+#    #+#             */
/*   Updated: 2023/03/30 22:08:04 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param str: 
 * @param start: 
 * @param len_sub: 
 * @return char* sub: 
 */
char	*ft_substr(char const *str, unsigned int start, size_t len_sub)
{
	char	*sub;
	size_t	end_str;
	size_t	i;

	if (str == NULL)
		return (NULL);
	end_str = ft_strlen(str);
	if (len_sub > end_str)
		len_sub = end_str;
	sub = (char *)malloc(sizeof(char) * (len_sub + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len_sub && start < end_str)
		sub[i++] = (char)str[start++];
	sub[i] = '\0';
	return (sub);
}
