/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:36:58 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/16 18:57:51 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_packet	g_stor;

static void	signal_handler(int signum, siginfo_t *info,
	void *ucontext __attribute__((unused)))
{
	if (g_stor.recv_count == 0)
		g_stor.packet = 0;
	g_stor.pid = info->si_pid;
	if (signum == SIGUSR1)
		g_stor.packet = (g_stor.packet << 1) + BIT_OFF;
	if (signum == SIGUSR2)
		g_stor.packet = (g_stor.packet << 1) + BIT_ON;
	if (++g_stor.recv_count == 8)
		ft_putchar_fd(g_stor.packet, STDOUT_FILENO);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_stor.recv_count = 0;
	while (g_stor.recv_count || pause())
	{
		if (usleep(EXT_EARLY) && g_stor.recv_count != 8)
			g_stor.recv_count = 9;
		if (g_stor.recv_count == 8 || usleep(MAX_WAIT_TIME) == 0)
		{
			if (g_stor.recv_count == 8)
				kill(g_stor.pid, COMM_SUC);
			else
				kill(g_stor.pid, COMM_ERR);
			g_stor.recv_count = 0;
		}
	}
	return (0);
}

// static t_packet	g_stor;

// static void	signal_handler(int signum, siginfo_t *info,
// 	void *ucontext __attribute__((unused)))
// {
// 	if (g_stor.recv_count == 0)
// 		g_stor.packet = 0;
// 	g_stor.pid = info->si_pid;
// 	if (signum == SIGUSR1)
// 		g_stor.packet = (g_stor.packet << 1) + BIT_OFF;
// 	if (signum == SIGUSR2)
// 		g_stor.packet = (g_stor.packet << 1) + BIT_ON;
// 	if (++g_stor.recv_count == 8)
// 		ft_putchar_fd(g_stor.packet, STDOUT_FILENO);
// }

// int	main(void)
// {
// 	struct sigaction	sa;

// 	ft_putnbr_fd(getpid(), STDOUT_FILENO);
// 	ft_putchar_fd('\n', STDOUT_FILENO);
// 	sa.sa_sigaction = signal_handler;
// 	sa.sa_flags = SA_SIGINFO;
// 	sigemptyset(&sa.sa_mask);
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);
// 	g_stor.recv_count = 0;
// 	while (g_stor.recv_count || pause())
// 	{
// 		if (usleep(EXT_EARLY) && g_stor.recv_count != 8)
// 		{
// 			g_stor.recv_count = 9;
// 			ft_putchar_fd('-', STDOUT_FILENO);
// 		}
// 		if (g_stor.recv_count == 8 || usleep(MAX_WAIT_TIME) == 0)
// 		{
// 			if (g_stor.recv_count == 8)
// 				kill(g_stor.pid, COMM_SUC);
// 			else
// 			{
// 				ft_putchar_fd('+', STDOUT_FILENO);
// 				kill(g_stor.pid, COMM_ERR);
// 			}
// 			g_stor.recv_count = 0;
// 		}
// 	}
// 	return (0);
// }
