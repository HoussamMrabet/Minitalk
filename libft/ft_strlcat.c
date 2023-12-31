/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:22:25 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/02 21:17:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen);
	i = 0;
	dstlen = 0;
	while (*(dst + dstlen) && dstlen < dstsize)
	{
		dstlen++;
	}
	while (*(src + i) && dstlen + i + 1 < dstsize)
	{
		*(dst + i + dstlen) = *(src + i);
		i++;
	}
	if (dstlen + i < dstsize)
	{
		*(dst + i + dstlen) = '\0';
	}
	return (dstlen + srclen);
}
