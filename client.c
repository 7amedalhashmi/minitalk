#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int errHandler(int pid, char *str)
{
	if (pid <= 1000 || pid >= 10000)
	{
		write(1, "Invalid PID number\n", 18);
		return(0);
	}
	else if (*str == '\0')
	{
		write(1, "Nothing to send\n", 16);
		return(0);
	}
	return(1);
}

void sigToKill(pid_t pid, char *str)
{
	int i;

	while (*str != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i & 1) == 0)
				kill(pid, SIGUSR1);
            else if ((*str >> i & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		str++;
	}
}

int main(int arc, char **arg)
{
	if (arc != 3)
	{
		printf("Invalid number of arguments\n");
		return(0);
	}
	else if (errHandler(atoi(arg[1]), arg[2]) == 0)
	{
		return(0);
	}
	sigToKill(atoi(arg[1]), arg[2]);
	return(0);
}
