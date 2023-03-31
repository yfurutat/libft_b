/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:35:07 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 15:15:47 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//10L
/**
 * @brief 
 * 
 * @param str 
 * @param proc_func 
 */
void	ft_striteri(char *str, void (*proc_func)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (str == NULL || proc_func == NULL)
		return ;
	while (str[i] != '\0')
	{
		proc_func(i, &str[i]);
		i += 1;
	}
}

// void	ft_toupper_p(unsigned int n, char *str)
// {
// 	if (*str >= 'a' && *str <= 'z')
// 		*str += ('A' - 'a');
// }

// int	main(void)
// {
// 	char	str[] = "abcdefghijklmno";

// 	ft_striteri(str, ft_toupper_p);
// 	printf("%s\n", str);
// 	return (0);
// }
