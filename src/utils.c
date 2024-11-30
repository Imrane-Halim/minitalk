/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihalim <ihalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:01:08 by ihalim            #+#    #+#             */
/*   Updated: 2024/11/28 19:01:18 by ihalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	send_signal(int pid, int sig)
{
	if (kill(pid, sig) != 0)
		error("\nError sending the signal!\n");
}
