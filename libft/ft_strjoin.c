/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:26:02 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/03 03:56:31 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(str + i + j) = *(s2 + j);
		j++;
	}
	*(str + i + j) = '\0';
	return (str);
}
