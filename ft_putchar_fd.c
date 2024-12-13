/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:27:12 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 05:43:14 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// ssize_t	ft_putchar_fd(char c, int fd)
// {
// 	#define EINV_ARG (-2);

// 	if (fd < 0)
// 		return (EINV_ARG);
// 	return (write(fd, &c, 1));
// }
