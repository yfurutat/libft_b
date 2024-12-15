/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:28:59 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 04:43:27 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//7L
/**
 * @brief 
 * 
 * @param str 
 * @param fd 
 */
void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str != '\0')
	{
		ft_putchar_fd(*str, fd);
		str += 1;
	}
}

//6L
// void	ft_putstr_fd(char *str, int fd)
// {
// 	size_t	len;

// 	if (str == NULL)
// 		return ;
// 	len = ft_strlen(str);
// 	write(fd, str, len);
// }

//4L
// void	ft_putstr_fd(char *str, int fd)
// {
// 	if (str == NULL)
// 		return ;
// 	while (*str != '\0')
// 		ft_putchar_fd(*str++, fd);
// }

ssize_t	ft_putstr_fd_for_ft_printf(char *str, int fd, ssize_t ret)
{
	size_t	len;
	ssize_t tmp;

	if (str == NULL)
		return (write(fd, "(null)", 6));
	if (fd < 0)
		return (-1);
	len = ft_strlen(str);
	if (len > (size_t)INT_MAX || ret > (ssize_t)INT_MAX - (ssize_t)len)
		return (-1);
	tmp = write(fd, str, len);	
	if (tmp != len)
		return (-1);
	return (ret + tmp);
}
