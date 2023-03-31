/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:46:37 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 08:06:03 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param node 
 * @param f_del 
 */
void	ft_lstclear(t_list **node, void (*f_del)(void *))
{
	t_list	*tmp;

	if (node == NULL || f_del == NULL)
		return ;
	while (*node != NULL)
	{
		tmp = (*node)->next;
		ft_lstdelone(*node, f_del);
		(*node) = tmp;
	}
}
