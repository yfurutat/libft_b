/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:36:38 by yuske             #+#    #+#             */
/*   Updated: 2025/06/29 20:46:05 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	iter_fill_str_with_chr_by_n(unsigned char *str, unsigned char c, \
	size_t n);

//11L
/**
 * @brief 
 * 
 * @param mem 
 * @param chr 
 * @param n_toset 
 * @return void* 
 */
// void	*ft_memset(void *mem, int chr, size_t num_bytes_to_set_chr)
// {
// 	unsigned char	*mem_caster;
// 	unsigned char	chr_caster;
// 	size_t			i;

// 	i = 0;
// 	chr_caster = (unsigned char)chr;
// 	mem_caster = (unsigned char *)mem;
// 	while (i < num_bytes_to_set_chr)
// 	{
// 		mem_caster[i] = chr_caster;
// 		i += 1;
// 	}
// 	return (mem);
// }

//2
// void	*ft_memset(void *mem, int chr, size_t num_bytes_to_set_chr)
// {
// 	mem = (void*)iter_fill_str_with_chr_by_n((unsigned char*)mem, (unsigned char)chr, num_bytes_to_set_chr);
// 	return (mem);
// }

// char	*iter_fill_str_with_chr_by_n(unsigned char *str, unsigned char c, size_t n)
// {
// 	size_t i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		str[i] = c;
// 		i += 1;
// 	}
// 	return ((char*)str);
// }

void	*ft_memset(void *mem, int chr, size_t num_bytes_to_set_chr)
{
	iter_fill_str_with_chr_by_n((unsigned char *)mem, (unsigned char)chr, \
		num_bytes_to_set_chr);
	return (mem);
}

size_t	iter_fill_str_with_chr_by_n(unsigned char *str, \
	unsigned char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i += 1;
	}
	return (i);
}
