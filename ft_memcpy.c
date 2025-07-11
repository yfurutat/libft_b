/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:27:26 by yuske             #+#    #+#             */
/*   Updated: 2023/04/03 23:31:37 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//15L
/**
 * @brief 
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
// void	*ft_memcpy(void *dst, const void *src, size_t n_cpy)
// {
// 	size_t				i;
// 	unsigned char		*dst_bin;
// 	const unsigned char	*src_bin;

// 	if (dst == src)
// 		return (NULL);
// 	dst_bin = (unsigned char *)dst;
// 	src_bin = (const unsigned char *)src;
// 	i = 0;
// 	while (i < n_cpy)
// 	{
// 		dst_bin[i] = src_bin[i];
// 		i += 1;
// 	}
// 	return (dst_bin);
// }
// 	// if (!dst && !src)

static void	_iter_copy_src_to_dest(unsigned char *dest, const unsigned char *src, size_t end);

void	*ft_memcpy(void *dest, const void *src, size_t n_cpy)
{
	if (dest == src)
		return (NULL);
	iter_copy_src_to_dest((unsigned char *)dest, (const unsigned char *)src, n_cpy);
	return (dest);
}

static void	_iter_copy_src_to_dest(unsigned char *dest, const unsigned char *src, size_t end)
{
	size_t	i;

	i = 0;
	while (i < end)
	{
		dest[i] = src[i];
		i += 1;
	}
}

// void	iter_copy_src_to_dest(char *dest, const char *src, size_t end)
// {
// 	size_t	i;

// 	i = 0;
// 	while (end > i + 1 && src[i] != '\0')
// 	{
// 		dest[i] = src[i];
// 		i += 1;
// 	}
// 	dest[i] = '\0';
// }

