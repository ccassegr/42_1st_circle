/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccassegr <ccassegr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:39:09 by ccassegr          #+#    #+#             */
/*   Updated: 2020/11/27 17:21:47 by ccassegr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	size_t	i;
	t_list	*lstnext;

	i = ft_lstsize(*lst);
	if (del == 0 || *lst == 0)
		return ;
	while (i > 0)
	{
		lstnext = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = lstnext;
		i--;
	}
	lst = NULL;
}
