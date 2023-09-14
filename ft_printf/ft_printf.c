/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:51:29 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/01/28 23:05:02 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char s, int *len, va_list my_va)
{
	if (s == 'c')
		ft_putchar(va_arg(my_va, int), len);
	else if (s == 's')
		ft_putstr(va_arg(my_va, char *), len);
	else if (s == 'p')
	{
		ft_putstr("0x", len);
		ft_writepointer(va_arg(my_va, unsigned long), len);
	}
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(my_va, int), len);
	else if (s == 'u')
		ft_putnbrunsgn(va_arg(my_va, unsigned int), len);
	else if (s == 'x')
		ft_makehexadecimal(va_arg(my_va, unsigned int), 'x', len);
	else if (s == 'X')
		ft_makehexadecimal(va_arg(my_va, unsigned int), 'X', len);
	else if (s == '%')
		ft_writepercent(len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	my_va;

	va_start(my_va, s);
	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 37)
		{
			i++;
			ft_format(s[i], &len, my_va);
		}
		else
			ft_putchar(s[i], &len);
		i++;
	}
	va_end(my_va);
	return (len);
}
