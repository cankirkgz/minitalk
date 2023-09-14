/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:37:59 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/14 00:02:36 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal_received(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Successful!\n");
}

int	send_character_bits(int server_pid, char character)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((character >> bit_index) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				return (-1);
		}
		bit_index--;
		usleep(150);
	}
	return (1);
}

void	send_message(int server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		if (send_character_bits(server_pid, message[i]) > 0)
			i++;
		else
		{
			ft_printf("Failure! Message could not reach the server!\n");
			break ;
		}
	}
	send_character_bits(server_pid, '\n');
	send_character_bits(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	unsigned int	server_pid;

	if (argc != 3)
	{
		ft_printf("Invalid argument!\nUsage: [program name(./client)]\
		[process id of the server]\
		[Message]\n");
		return (0);
	}
	signal(SIGUSR1, handle_signal_received);
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	return (0);
}
