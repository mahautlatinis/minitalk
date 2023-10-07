/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:46:39 by malatini          #+#    #+#             */
/*   Updated: 2023/10/07 19:26:27 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#if __APPLE__
# define IS_MACOS 1
#else
# define IS_MACOS 0
#endif

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	decrypt_message(int num);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	send_char_as_signals_signals(char c, int pid);

#endif
