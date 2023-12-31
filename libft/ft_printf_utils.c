/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:51:37 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/31 16:38:25 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_char(int c, int *len)
{
	if (*len != -1)
	{
		if (write(1, &c, 1) == (-1))
			*len = -1;
		else
			(*len)++;
	}
}

void	ft_putnbr(long nb, int	*len)
{
	if (nb < 0)
	{
		ft_print_char('-', len);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, len);
	ft_print_char(nb % 10 + 48, len);
}

void	ft_print_s(char *s, int *len)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		ft_print_s("(null)", len);
	else
	{
		while (*(s + i))
		{
			ft_print_char(*(s + i), len);
			i++;
		}
	}
}

void	ft_print_hex(unsigned long nb, char x, int *len)
{
	if (x == 'p')
	{
		ft_print_s("0x", len);
		x = 'x';
	}
	if (nb >= 16)
		ft_print_hex(nb / 16, x, len);
	if (x == 'x')
		ft_print_char("0123456789abcdef"[nb % 16], len);
	else
		ft_print_char("0123456789ABCDEF"[nb % 16], len);
}
