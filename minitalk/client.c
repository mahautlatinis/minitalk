/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:53:59 by malatini          #+#    #+#             */
/*   Updated: 2023/10/07 19:32:40 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

#ifndef SIGUSR1
# define SIGUSR1 30
#endif 

#ifndef SIGUSR2
# define SIGUSR2 31 
#endif

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	max;
	long	sign;
	long	result;

	i = 0;
	max = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (max >= 1)
			return (0);
		if (str[i] == '-')
			sign = -sign;
		max++;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return ((int)result * sign);
}

void	send_char_as_signals(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc > 1 && argc < 4)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
		{
			write(2, "Error.\nMissing PID.\n", 21);
			exit (EXIT_FAILURE);
		}
		if (argc == 3)
		{
			while (argv[2][i])
				send_char_as_signals(argv[2][i++], pid);
		}
		else if (argc == 2)
		{
			write(2, "Error.\nYou did not inputed a string.\n", 38);
			exit (EXIT_FAILURE);
		}
	}
	exit (EXIT_SUCCESS);
}
