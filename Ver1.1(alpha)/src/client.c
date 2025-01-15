/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:23:38 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/04 21:21:47 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static unsigned int	g_sig_state;

static void	signal_handler(int signum)
{
	g_sig_state = signum;
	if (signum == COMM_ERR)
		ft_putstr_fd("timeout\n", STDERR_FILENO);
}

static void	tobit(pid_t pid, uint8_t num)
{
	unsigned int	size;

	size = sizeof(num) * 8;
	while (size--)
	{
		usleep(100);
		if (num >> size & BIT_ON)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc < 3)
	{
		ft_putstr_fd("format error\n", STDERR_FILENO);
		return (-1);
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		tobit(pid, *argv[2]);
		if (usleep(15000) == 0)
		{
			ft_putstr_fd("pid error\n", STDERR_FILENO);
			return (-1);
		}
		if (g_sig_state == COMM_SUC)
			argv[2]++;
	}
	ft_putstr_fd("success!\n", STDOUT_FILENO);
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
