/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:09:02 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/31 16:37:13 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (*(str + i) && (*(str + i) == ' '
			|| (*(str + i) >= 9 && *(str + i) <= 13)))
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			sign = -sign;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + *(str + i) - 48;
		i++;
	}
	return (sign * (int)res);
}
