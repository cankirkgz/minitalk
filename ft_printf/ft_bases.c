/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:38:35 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/12 22:21:04 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_makehexadecimal(unsigned int n, char c, int *len)
{
	char	*base;
	char	*baseupper;

	baseupper = "0123456789ABCDEF";
	base = "0123456789abcdef";
	if (n > 15)
	{
		ft_makehexadecimal(n / 16, c, len);
		ft_makehexadecimal(n % 16, c, len);
	}
	else
	{
		if (c == 'x')
			ft_putchar(base[n % 16], len);
		else if (c == 'X')
			ft_putchar(baseupper[n % 16], len);
	}
}

void	ft_writepointer(unsigned long s, int *len)
{
	if (s > 15)
		ft_writepointer((s / 16), len);
	ft_putchar("0123456789abcdef"[s % 16], len);
}
