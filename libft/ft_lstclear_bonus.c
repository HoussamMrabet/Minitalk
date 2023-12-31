/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:05:08 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/03 21:31:41 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*l;

	if (lst && del)
	{
		while (*lst)
		{
			l = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = l;
		}
		lst = NULL;
	}
}
