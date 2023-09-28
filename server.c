/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:55:37 by malatini          #+#    #+#             */
/*   Updated: 2023/09/28 19:02:17 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

/* On fait un ft_putnbr pour afficher le pid */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

/* Traduction des différents bits envoyés pour reconstruire le char */
void	translate_message(int num)
{
	static int	power;
	static char	byte;

	if (num == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar(byte);
		power = 0;
		byte = 0;
	}
}

/* Je vais pouvoir afficher le caractère une fois les 8 bits transmis */
int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr("My pid is: ");
		ft_putnbr(pid);
		ft_putchar('\n');
		signal(SIGUSR1, translate_message);
		signal(SIGUSR2, translate_message);
		while (42)
			pause();
	}
	return (0);
}
