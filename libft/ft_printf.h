/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:08:04 by hmrabet           #+#    #+#             */
/*   Updated: 2023/12/31 16:38:33 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_print_char(int c, int *len);
void	ft_print_s(char *s, int *len);
void	ft_putnbr(long nb, int	*len);
void	ft_print_hex(unsigned long nb, char x, int *len);
int		ft_printf(const char *s, ...);

#endif
