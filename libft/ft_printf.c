/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:57:55 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/31 16:38:30 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_spec(char *s, va_list v, int *len, size_t *i)
{
	*i += 2;
	if (*s == '%')
		ft_print_char('%', len);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(v, int), len);
	else if (*s == 'u')
		ft_putnbr(va_arg(v, unsigned int), len);
	else if (*s == 'c')
		ft_print_char(va_arg(v, int), len);
	else if (*s == 's')
		ft_print_s(va_arg(v, char *), len);
	else if (*s == 'x' || *s == 'X')
		ft_print_hex(va_arg(v, unsigned int), *s, len);
	else if (*s == 'p')
		ft_print_hex(va_arg(v, unsigned long), *s, len);
}

static int	ft_is_valid(char c, char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_format(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
	{
		if (*(s + i) == '%')
		{
			i++;
			if (!ft_is_valid(*(s + i), "diuscxXp%"))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	v;
	size_t	i;
	int		len;

	va_start(v, s);
	i = 0;
	len = 0;
	if (!ft_check_format(s))
		return (-1);
	while (*(s + i))
	{
		if (*(s + i) == '%')
		{
			ft_print_spec((char *)(s + i + 1), v, &len, &i);
			continue ;
		}
		ft_print_char(*(s + i), &len);
		i++;
	}
	va_end(v);
	return (len);
}
