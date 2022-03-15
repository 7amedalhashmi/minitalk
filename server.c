#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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
		write(1, &str, 1);
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
	printf("%d\n", pid);
	//ft_putnbr(pid);
    signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
    while (1)
        pause();
    return 0;
}
