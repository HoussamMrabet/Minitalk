/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:31:09 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/31 16:38:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(NULL);
		if (!tmp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		tmp->content = f(lst->content);
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (res);
}
