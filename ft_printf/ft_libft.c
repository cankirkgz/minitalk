/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:06:27 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/01/28 23:02:51 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		*len += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		*len += 1;
	}
}

void	ft_putnbr(int n, int *len)
{
	int		sign;
	char	c;

	sign = 1;
	if (n < 0)
	{
		ft_putchar('-', len);
		sign = -1;
	}
	if (n / 10)
		ft_putnbr(n / 10 * sign, len);
	c = '0' + n % 10 * sign;
	ft_putchar(c, len);
}

void	ft_putnbrunsgn(unsigned int n, int *len)
{
	char	c;

	if (n / 10)
		ft_putnbrunsgn(n / 10, len);
	c = '0' + n % 10;
	ft_putchar(c, len);
}

void	ft_writepercent(int *len)
{
	write(1, "%", 1);
	*len += 1;
}
