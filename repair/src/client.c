/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:23:38 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/04 17:15:11 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static unsigned int	g_sig_state;

static void	signal_handler(int signum)
{
	g_sig_state = signum;
}

static void	tobit(pid_t pid, uint8_t num)
{
	unsigned int	size;

	size = sizeof(num) * 8;
	while (size--)
	{
		if (num >> size & BIT_ON)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc < 3)
		return (-1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		tobit(pid, *argv[2]);
		pause();
		if (g_sig_state == COMM_SUC)
			argv[2]++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	pid_t	pid;

// 	if (argc < 3)
// 		return (-1);
// 	signal(SIGUSR1, signal_handler);
// 	signal(SIGUSR2, signal_handler);
// 	pid = ft_atoi(argv[1]);
// 	while (*argv[2])
// 	{
// 		tobit(pid, *argv[2]);
// 		pause();
// 		printf("%d\n", g_sig_state);
// 		if (g_sig_state == COMM_SUC)
// 			argv[2]++;
// 	}
// 	return (0);
// }
