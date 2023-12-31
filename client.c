/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:30:26 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/31 23:27:32 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_inputs(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (1);
	while (argv[1][i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (1);
		i++;
	}
	return (0);
}

static void	send_char(int id, unsigned char c)
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

	i = 0;
	if (check_inputs(argc, argv))
	{
		ft_printf("\x1b[31minvalid input!\n\x1b[0m");
		return (-1);
	}
	id = ft_atoi(argv[1]);
	if (id <= 0)
	{
		ft_printf("\x1b[31minvalid PID!\n\x1b[0m");
		return (-1);
	}
	while (argv[2][i])
	{
		send_char(id, argv[2][i]);
		i++;
	}
	send_char(id, '\n');
	return (0);
}
