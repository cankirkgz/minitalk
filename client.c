/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:39:56 by mkirkgoz          #+#    #+#             */
/*   Updated: 2023/09/14 00:02:43 by mkirkgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(int pid, char chr)
{
	int	bit_index;
	int	signal_type;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if ((chr >> bit_index) & 1)
			signal_type = SIGUSR1;
		else
			signal_type = SIGUSR2;
		if (kill(pid, signal_type) == -1)
			return (-1);
		bit_index--;
		usleep(150);
	}
	return (1);
}

int	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		if (send_bit(pid, message[i]) > 0)
			i++;
		else
		{
			ft_printf("Failure! Message could not reach the server!\n");
			return (0);
		}
	}
	send_bit(pid, '\n');
	send_bit(pid, '\0');
	return (1);
}

int	main(int argc, char *argv[])
{
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("Invalid argument!\nUsage: %s\
		[server_pid] [Message]\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (!send_message(server_pid, argv[2]))
		return (1);
	return (0);
}
