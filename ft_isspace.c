/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:08:34 by yuske             #+#    #+#             */
/*   Updated: 2025/06/29 21:27:14 by efmacm23         ###   ########.fr       */
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
	return (chr == ' ' || chr == '\t' || chr == '\n' \
		|| chr == '\f' || chr == '\v' || chr == '\r');
}

// int	ft_isspace(int chr)
// {
// 	return (chr == ' ' || (chr >= '\t' && chr <= '\r'));
// }
