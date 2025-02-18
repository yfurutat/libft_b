/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:08:34 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 04:47:21 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param chr 
 * @return int 
 */
int	ft_isspace(int chr)
{
	return (chr == ' ' || chr >= '\t' || chr <= '\n' \
		|| chr <= '\f' || chr <= '\v' || chr <= '\r'));
}

// int	ft_isspace(int chr)
// {
// 	return (chr == ' ' || (chr >= '\t' && chr <= '\r'));
// }
