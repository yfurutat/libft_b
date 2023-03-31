/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 04:26:59 by yuske             #+#    #+#             */
/*   Updated: 2023/03/30 05:13:01 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//9L
/**
 * @brief 
 * 
 * @param str 
 * @param chr 
 * @return char* 
 * @var const char *head
 */
char	*ft_strrchr(const char *str, int chr)
{
	const char	*head;

	head = str;
	str += ft_strlen(str);
	while (*str != (unsigned char)chr && *str != *head)
		str -= 1;
	if (*str == (unsigned char)chr)
		return ((char *)str);
	return (NULL);
}
