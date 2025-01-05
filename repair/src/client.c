/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:23:38 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/12/26 14:22:18 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static volatile sig_atomic_t	g_sig_state;

static void	signal_handler(int signum)
{
	g_sig_state = signum;
}

static void	tobit(pid_t pid, char num)
{
	uint8_t	sizeof_type;

	sizeof_type = 8;
	while (sizeof_type--)
	{
		usleep(20);
		if (num >> sizeof_type & BIT_ON)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
	}
}

static void	signalup(pid_t pid, char *str)
{
	while (usleep(500) == 0 && g_sig_state == COMM_ERR)
	{
		if (*str)
			tobit(pid, *str);
		else
			tobit(pid, SIG_END);
		if (SIG_RETRY < retry)
		{
			ft_putstr_fd("Server error.", STDOUT_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	ft_putstr_fd("Success!\n", STDOUT_FILENO);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc < 3)
	{
		ft_putstr_fd("Format error : ./client [pid] [text]\n", STDERR_FILENO);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	g_sig_state = COMM_ERR;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	kill(pid, SIGUSR2);
	if (usleep(1000) == 0)
		ft_putstr_fd("Pid error\n", STDERR_FILENO);
	else if (g_sig_state == COMM_ERR)
		ft_putstr_fd("Server is busy. Please wait a moment and try again.\n",
			STDOUT_FILENO);
	else
		signalup(pid, argv[2]);
	return (0);
}

// #include <stdio.h>

// static void	tobiterror(pid_t pid, uint8_t num)
// {
// 	unsigned int	size;

// 	size = sizeof(num) * 7;
// 	while (size--)
// 	{
// 		if (num >> size & BIT_ON)
// 			kill(pid, SIGUSR2);
// 		else
// 			kill(pid, SIGUSR1);
// 		usleep(50);
// 	}
// }

// int	main(int argc, char *argv[])
// {
// 	int i;
// 	pid_t	pid;

// 	if (argc < 3)
// 		return (-1);
// 	signal(SIGUSR1, signal_handler);
// 	signal(SIGUSR2, signal_handler);
// 	pid = ft_atoi(argv[1]);
// 	i = 0;
// 	while (*argv[2])
// 	{
// 		if (i % 7 == 0)
// 			tobiterror(pid, *argv[2]);
// 		else
// 			tobit(pid, *argv[2]);
// 		i++;
// 		if (usleep(500) == 0)
// 		{
// 			ft_putstr_fd("pid erro\n", STDERR_FILENO);
// 			return (-1);
// 		}
// 		printf("%d\n", g_sig_state);
// 		if (g_sig_state == COMM_SUC)
// 			argv[2]++;
// 	}
// 	return (0);
// }
