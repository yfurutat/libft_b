/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:35:07 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 14:12:29 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// strieri, stmapi: unsigned int では無限ループする可能性がある 

//10L
/**
 * @brief 
 * 
 * @param str 
 * @param fnc 
 */
void	ft_striteri(char *str, void (*fnc)(unsigned int, char*))
{
	size_t	start;
	size_t	end;
	
	if (str == NULL || fnc == NULL)
	{
		errno = EINVAL;
		return ;
	}
	end = ft_strlen(str);
	if (end > UINT_MAX)
	{
		errno = EOVERFLOW;
		return ;
	}
	start = 0;
	while (start < end)
	{
		fnc((unigned int)start, &str[start]);
		start += 1;
	}
}
		// fnc((unigned int)start, str);

// void	ft_striteri(char *str, void (*fnc)(unsigned int, char*), unsigned int start)
// {
// 	size_t	end;
	
// 	if (str == NULL || fnc == NULL)
// 	{
// 		errno = EINVAL;
// 		return ;
// 	}
// 	end = ft_strlen(str);
// 	if (end > UINT_MAX)
// 	{
// 		errno = EOVERFLOW;
// 		return ;
// 	}
// 	while ((size_t)start < end)
// 	{
// 		fnc((unigned int)start, &str[start]);
// 		// fnc((unigned int)start, str);
// 		start += 1;
// 	}
// }

// fnc((unigned int)start, str);
void to_upper(unsigned int i, char *c)
{
	(void)i;

	*c = ft_toupper(*c);
}

// fnc((unigned int)start, &str[start);
void to_upper_if_even(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
}

// void to_upper(unsigned int i, char *c)
// {
//     c[i] = ft_toupper(c[i]);
// }

// void	ft_striteri(char *str, void (*fnc)(unsigned int, char*))
// {
// 	// unsigned int	i;
// 	size_t	i;

// 	if (str == NULL || fnc == NULL)
// 		return ;
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		fnc(i, &str[i]);
// 		i += 1;
// 	}
// }

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
