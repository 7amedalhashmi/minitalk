/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halhashm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:47:27 by halhashm          #+#    #+#             */
/*   Updated: 2022/03/15 17:13:11 by halhashm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_error(char *error)
{
	while (*error)
		write(1, error++, 1);
	exit(1);
}

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				sign;
	int				i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		num = num * 10;
		num = num + (str[i++] - '0');
	}
	if (num > 2147483648 && sign == -1)
		return (0);
	else if (num > 2147483647 && sign == 1)
		return (-1);
	return ((int) num * sign);
}

int	errhandler(int pid, char *str)
{
	if (pid <= 1000 || pid >= 100000)
		ft_error("Invalid PID number\n");
	else if (*str == '\0')
		ft_error("Nothing to send\n");
	return (1);
}

void	sigtokill(pid_t pid, char *str)
{
	int	i;

	while (*str != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i & 1) == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error("Invalid PID\n");
			}
			else if ((*str >> i & 1) == 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error("Invalid PID\n");
			}
			usleep(150);
			i--;
		}
		str++;
	}
}

int	main(int arc, char **arg)
{
	if (arc != 3)
		ft_error("Invalid number of arguments\n");
	else if (errhandler(ft_atoi(arg[1]), arg[2]) == 0)
		return (0);
	sigtokill(ft_atoi(arg[1]), arg[2]);
	return (0);
}
