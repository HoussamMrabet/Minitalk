/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:55:16 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/02 14:21:55 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;
	char	ch;

	ch = (char)c;
	str = (char *)s;
	i = ft_strlen(str);
	if (ch == '\0')
		return (str + i);
	i++;
	while (i > 0)
	{
		i--;
		if (*(str + i) == ch)
			return (str + i);
	}
	return (NULL);
}
