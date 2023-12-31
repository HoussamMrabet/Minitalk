/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:06:23 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/03 03:54:20 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (*(s + i))
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
