/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:16:52 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 03:52:11 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//20L
/**
 * @brief 
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
// void	*ft_memmove(void *dst, const void *src, size_t n)
// {
// 	unsigned char		*dst_bin;
// 	const unsigned char	*src_bin;

// 	if (dst == src)
// 		return (NULL);
// 	dst_bin = (unsigned char *)dst;
// 	src_bin = (const unsigned char *)src;
// 	if (n == 0)
// 		return (dst_bin);
// 	else if (dst > src)
// 	{
// 		while (n > 0)
// 		{
// 			n -= 1;
// 			dst_bin[n] = src_bin[n];
// 		}
// 	}
// 	else
// 		dst_bin = ft_memcpy(dst, src, n);
// 	return (dst_bin);
// }
// 	// if (dst == NULL && src == NULL)
// 		// ft_memcpy(dst, src, n);

void	*ft_memcpy(void *dest, const void *src, size_t n_cpy);
static void	_iter_copy_src_to_dest(unsigned char *dest, const unsigned char *src, size_t end);
static void	_iter_copy_src_to_dest_from_end(unsigned char *dest, const unsigned char *src, size_t end);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (NULL);
	if (n == 0)
		return (dest);
	else if (dst > src)
		_iter_copy_src_to_dest_from_end((unsigned char *)dest, (const unsigned char *)src, n);
	else
		return (ft_memcpy(dst, src, n));
	return (dest);
}

static void	_iter_copy_src_to_dest_from_end(unsigned char *dest, const unsigned char *src, size_t end)
{
	while (end > 0)
	{
		end -= 1;
		dst_bin[end] = src_bin[end];
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n_cpy)
{
	if (dst == src)
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

