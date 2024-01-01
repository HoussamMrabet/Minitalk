/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:30:26 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/01 14:08:00 by hmrabet          ###   ########.fr       */
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
		pause();
	}
}

void feedback(int sig)
{
	if(sig == SIGUSR1)
		ft_printf("SIGUSR1\n");
	else if(sig == SIGUSR2)
		ft_printf("SIGUSR2\n");
}

int	main(int argc, char **argv)
{
	int	i;
	int	id;
	struct sigaction	sa;

	sa.sa_handler = feedback;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
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
	send_char(id, '\0');
	exit(0);
}
