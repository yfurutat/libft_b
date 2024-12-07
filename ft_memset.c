/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:36:38 by yuske             #+#    #+#             */
/*   Updated: 2023/04/07 02:44:14 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//11L
/**
 * @brief 
 * 
 * @param mem 
 * @param chr 
 * @param n_toset 
 * @return void* 
 */
void	*ft_memset(void *mem, int chr, size_t num_bytes_to_set_chr)
{
	unsigned char	*mem_caster;
	unsigned char	chr_caster;
	size_t			i;

	i = 0;
	chr_caster = (unsigned char)chr;
	mem_caster = (unsigned char *)mem;
	while (i < num_bytes_to_set_chr)
	{
		mem_caster[i] = chr_caster;
		i += 1;
	}
	return (mem);
}

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
