/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:49:34 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/03 20:23:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!*needle || (!len && !*needle))
		return ((char *)haystack);
	if (!len)
		return (NULL);
	res = (char *)haystack;
	i = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (*needle == '\0')
		return (res);
	while (i < len)
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j) && (i + j) < len)
		{
			if (needle[++j] == '\0')
				return (res + i);
		}
		i++;
	}
	return (NULL);
}
