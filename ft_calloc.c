/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:51:39 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 06:01:18 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 13L
/**
 * @brief 
 * 
 * @param num 
 * @param size 
 * @return void* 
 */
void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	if (size > SIZE_MAX / num)
		return (NULL);
	arr = malloc(num * size);
	if (arr != NULL)
		ft_bzero(arr, num * size);
	return (arr);
}
		// ft_calloc(1, 1);
		// return (NULL);
