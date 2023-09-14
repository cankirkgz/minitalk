/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:39:38 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/01/06 20:37:25 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	i;
	int	remainder;

	i = 0;
	remainder = 10;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / remainder;
	}
	return (i);
}

int	absolute_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = get_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	if (n == 0)
		*str = '0';
	if (n < 0)
		*str = '-';
	len--;
	while (len >= 0 && n != 0)
	{
		*(str + len) = absolute_val(n % 10) + '0';
		len--;
		n = n / 10;
	}
	return (str);
}
