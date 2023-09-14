/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:37:26 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/13 23:13:40 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_signal(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit_position = 7;
	static int	received_char = 0;
	int			received_bit;

	received_bit = 0;
	(void)ucontext;
	if (signum == SIGUSR1)
		received_bit = 1;
	else if (signum == SIGUSR2)
		received_bit = 0;
	received_char += (received_bit << bit_position);
	if (bit_position == 0 && received_char == 0)
		kill(info->si_pid, SIGUSR1);
	if (bit_position == 0)
	{
		write(1, &received_char, 1);
		bit_position = 7;
		received_char = 0;
	}
	else
		bit_position--;
}

void	setup_signal_handling(void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_sigaction = &receive_signal;
	sa_signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
}

int	main(void)
{
	ft_printf("Welcome to my Chat World!!!\n");
	ft_printf("My PID: %s\n", ft_itoa(getpid()));
	while (1)
		setup_signal_handling();
	return (EXIT_SUCCESS);
}
