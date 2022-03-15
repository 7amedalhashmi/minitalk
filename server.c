#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int c)
{
	unsigned int	i;

	i = c;
	if (c < 0)
	{
		ft_putchar('-');
		i = c * -1;
	}
	if (i / 10 != 0)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}

void ft_signal(int sig)
{
	static int i;
	static char str;

	i++;
    if (sig == SIGUSR2)
	{
		str |= 1;
	}
	if (i == 8)
	{
		ft_putchar(str);
		i = 0;
		str = 0;
	}
	else
	{
		str <<= 1;
	}
}

int main()
{
    pid_t pid;

	pid = getpid();
	write(1, "\nThe PID number is : ", 22);
	ft_putnbr(pid);
	ft_putchar('\n');
    signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
    while (1)
        pause();
    return 0;
}