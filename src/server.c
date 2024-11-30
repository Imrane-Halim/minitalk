/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:05:38 by ihalim            #+#    #+#             */
/*   Updated: 2024/11/30 09:51:52 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc.h"

void	to_string(int sig, siginfo_t *info, void *context)
{
	static short	current_bit;
	static int		c;

	if (sig == SIGUSR1)
		c |= (1 << current_bit);
	current_bit++;
	if (current_bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		current_bit = 0;
	}
	send_signal(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server PID: %d\n\n", getpid());
	sa.sa_sigaction = to_string;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
