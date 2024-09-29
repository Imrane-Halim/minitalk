#include "../inc.h"

void    to_string(int sig)
{
    static short    current_bit;
    static int     c;

    if (sig == SIGUSR1)
        c |= (1 << current_bit);  
    current_bit++;
    if (current_bit == 8)
    {
        ft_printf("%c", c);
        c = 0;
        current_bit = 0;
    }
}

int	main()
{
    ft_printf("server PID: %d\n\n", getpid());

    signal(SIGUSR1, to_string);
    signal(SIGUSR2, to_string);

    while (1)
        pause();
    return (0);
}