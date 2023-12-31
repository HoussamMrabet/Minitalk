/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:30:26 by houbet            #+#    #+#             */
/*   Updated: 2023/12/31 20:15:53 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int id, unsigned char c)
{
	int		i;
	int		b;

	i = 0;
	b = 128;
	while (i < 8)
	{
		if (c - b >= 0)
		{
			kill(id, SIGUSR1);
			c -= b;
		}
		else
			kill(id, SIGUSR2);
		i++;
		b /= 2;
		usleep(800);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	id;

	id = ft_atoi(argv[1]);
	i = argc - argc;
	while (argv[2][i])
	{
		send_char(id, argv[2][i]);
		i++;
	}
	return (0);
}
