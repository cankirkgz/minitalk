/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:40:12 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/13 22:16:31 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_signal(int signal)
{
	static int	num = 7;
	static char	c = 0;

	if (signal == SIGUSR1)
		c += (1 << num);
	if (num == 0)
	{
		write(1, &c, 1);
		num = 8;
		c = 0;
	}
	num--;
}

int	main(void)
{
	ft_printf("Welcome to my Chat World!!!\n");
	ft_printf("My PID: %s\n", ft_itoa(getpid()));
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		pause();
	return (0);
}
