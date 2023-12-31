/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:44:35 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/31 16:38:11 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	ch;

	ch = (char)c;
	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (*(str + i) == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
