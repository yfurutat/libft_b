/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:02:19 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 03:53:25 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// (dst != NULL, O)で crash しない 

//1. 14L
/**
 * @brief 
 * 
 * @param dst 
 * @param src 
 * @param len_cpy 
 * @return size_t 
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t len_cpy)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (len_cpy > 0)
	{
		while (len_cpy > i + 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i += 1;
		}
		dest[i] = '\0';
	}
	return (len_src);
}
	
