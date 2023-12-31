/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:30:21 by houbet            #+#    #+#             */
/*   Updated: 2023/12/31 20:16:54 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	byte_to_char(char *byte)
{
	unsigned char	c;
	int				i;
	int				b;

	c = 0;
	i = 0;
	b = 128;
	while (byte[i])
	{
		if (byte[i] == '1')
			c += b;
		b /= 2;
		i++;
	}
	return (c);
}

void	ft_append(int signal)
{
	static char	byte[] = "00000000";
	static int	i = 0;

	if (signal == SIGUSR1)
	{
		byte[i] = '1';
		i++;
	}
	else if (signal == SIGUSR2)
	{
		byte[i] = '0';
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", byte_to_char(byte));
		i = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, ft_append);
	signal(SIGUSR2, ft_append);
	while (1)
		pause();
	return (0);
}
