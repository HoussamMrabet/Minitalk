/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:50:28 by hmrabet           #+#    #+#             */
/*   Updated: 2023/11/03 03:44:26 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int	i;

	if (!(!s || !f))
	{
		i = 0;
		while (*(s + i))
		{
			f(i, (s + i));
			i++;
		}
	}
}
