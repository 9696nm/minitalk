/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:23:38 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/16 19:07:07 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_sig_state;

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
		usleep(SIGNAL_INTERVAL);
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
		if (usleep(PID_DETECTION) == 0)
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
