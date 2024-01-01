/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:30:21 by hmrabet           #+#    #+#             */
/*   Updated: 2024/01/01 14:07:14 by hmrabet          ###   ########.fr       */
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

static void	ft_append_bit(int signal, siginfo_t *info, void *context)
{
	static char	byte[] = "00000000";
	static int	i = 0;

	(void)context;
	if (signal == SIGUSR1)
	{
		byte[i] = '1';
		kill(info->si_pid, SIGUSR1);
		i++;
	}
	else if (signal == SIGUSR2)
	{
		byte[i] = '0';
		kill(info->si_pid, SIGUSR2);
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", byte_to_char(byte));
		i = 0;
	}
	usleep(800);
}

int	main(void)
{
	struct sigaction	siga;

	siga.sa_sigaction = ft_append_bit;
	siga.sa_flags = SA_SIGINFO;
	sigemptyset(&siga.sa_mask);
	sigaddset(&siga.sa_mask, SIGUSR1);
	sigaddset(&siga.sa_mask, SIGUSR2);
	ft_printf("PID : %d\n", getpid());
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
	exit(0);
}
