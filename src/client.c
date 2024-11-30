/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:05:15 by ihalim            #+#    #+#             */
/*   Updated: 2024/11/28 19:05:16 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc.h"

int	g_sig_recived;

void	confirm_handler(int signum)
{
	g_sig_recived = 1;
	(void)signum;
}

void	send_bits(int pid, int signum)
{
	if (signum == 1)
		send_signal(pid, SIGUSR1);
	else
		send_signal(pid, SIGUSR2);
	while (!g_sig_recived)
		pause();
	g_sig_recived = 0;
}

void	send_byte(int pid, char c)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		send_bits(pid, (c >> current_bit) & 1);
		usleep(100);
		current_bit++;
	}
}

void	send_string(int pid, char *string)
{
	while (*string)
		send_byte(pid, *string++);
	send_byte(pid, 6);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		error("Usage: ./client <PID> <STRING>\n");
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		error("Error: invalid PID\n");
	signal(SIGUSR1, confirm_handler);
	send_string(pid, av[2]);
	return (0);
}
