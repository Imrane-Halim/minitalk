#include "../inc.h"

void	error(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

void	send_signal(int pid, int sig)
{
	if (kill(pid, sig) != 0)
		error("\nError: signal was not sent, are u sure the PID is valid ?\n");
}

int send_byte(int pid, char c)
{
	int current_bit;
	
	current_bit = 0;
	while (current_bit < 8)
	{
		if (c & (1 << current_bit))
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		usleep(2000);
		current_bit++;
	}
	
}

int	send_string(int pid, char *string)
{
	while (*string != '\0')
		send_byte(pid, *string++);
	send_byte(pid, '\0');
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac < 3 || ac > 3)
		error("\nError: the client takes only 3 params: PID and a String\n");
	pid = ft_atoi(av[1]);
	if (pid == 0)
		error("\nError: invalid PID\n");
	send_string(pid, av[2]);
	return (0);
}

