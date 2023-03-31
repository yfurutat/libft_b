/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:24:16 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 06:22:12 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//14L
/**
 * @brief 
 * 
 * @param str 
 * @param trimmer_set 
 * @return char* 
 */
char	*ft_strtrim(char const *str, char const *trimmer)
{
	char	*trimmed;
	size_t	head;
	size_t	tail;

	if (!str || !trimmer)
		return (NULL);
	head = 0;
	while (ft_strchr(trimmer, str[head]) && str[head] != '\0')
		head += 1;
	tail = ft_strlen(str) - 1;
	while (ft_strchr(trimmer, str[tail]) && tail > head)
		tail -= 1;
	trimmed = ft_substr(str, head, tail - head + 1);
	return (trimmed);
}

//23L
// char	*ft_strtrim(char const *str, char const *trimmer_set)
// {
// 	char	*trimmed;
// 	size_t	head;
// 	size_t	tail;
// 	size_t	i;

// 	if (str == NULL || trimmer_set == NULL)
// 		return (NULL);
// 	else if (*str == '\0')
// 		return (ft_strdup(""));
// 	head = 0;
// 	while (ft_strchr(trimmer_set, str[head]) && str[head] != '\0')
// 		head += 1;
// 	tail = ft_strlen(str) - 1;
// 	while (ft_strchr(trimmer_set, str[tail]) && tail > head)
// 		tail -= 1;
// 	trimmed = (char *)ft_calloc(sizeof(char), (tail - head + 2));
// 	if (trimmed != NULL)
// 	{
// 		i = 0;
// 		while (head <= tail)
// 			trimmed[i++] = str[head++];
// 	}
// 	return (trimmed);
// }
