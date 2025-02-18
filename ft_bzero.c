/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:21:26 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 04:45:11 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param mem 
 * @param n_zero 
 */
void	ft_bzero(void *mem, size_t num_bytes_to_set_zero)
{
	ft_memset(mem, 0, num_bytes_to_set_zero);
}
