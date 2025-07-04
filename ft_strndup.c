/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:08:43 by yuske             #+#    #+#             */
/*   Updated: 2025/06/29 21:42:25 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = malloc(sizeof(char) * (n + 1));
	if (dup != NULL)
		ft_strlcpy(dup, str, n);
	return (dup);
}

// char	*ft_strndup(const char *str, size_t n)
// {
// 	char	*dup;
// 	size_t	i;

// 	dup = malloc(sizeof(char) * (n + 1));
// 	if (!dup)
// 		return (NULL);
// 	i = 0;
// 	while (i < n && str[i] != '\0')
// 	{
// 		dup[i] = str[i];
// 		i += 1;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }
	// if (str == NULL)
	// 	return (NULL);//the original is not equipped with null guards.

// #include <stdio.h>
// int	main(void)
// {
// 	char *str = "hello";

// 	printf("%s\n", strndup(str, 0));
// 	printf("%s\n", ft_strndup(str, 0));
// 	printf("%s\n", strndup(str, SIZE_MAX));
// 	printf("%s\n", ft_strndup(str, SIZE_MAX));
// 	printf("%s\n", strndup(NULL, 0));
// 	printf("%s\n", ft_strndup(NULL, 0));
// 	// printf("%s\n", strndup(NULL, 1));//segv
// 	// printf("%s\n", ft_strndup(NULL, 1));//segv
// 	return (0);
// }
