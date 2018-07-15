/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:33:38 by juwong            #+#    #+#             */
/*   Updated: 2018/06/29 14:58:32 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushback(t_list **lst, void *content, size_t content_size)
{
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	if (current)
	{
		while ((current)->next)
			current = current->next;
		current->next = ft_lstnew(content, content_size);
	}
	else
	{
		*lst = ft_lstnew(content, content_size);
	}
}
