/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:36:58 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/07 17:48:20 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_packet	g_stor;

static void	signal_handler(int signum, siginfo_t *info,
	void *ucontext __attribute__((unused)))
{
	if (g_stor.pid == 0)
	{
		g_stor.pid = info->si_pid;
		kill(info->si_pid, COMM_SUC);
	}
	else if (g_stor.pid != info->si_pid)
		kill(info->si_pid, COMM_ERR);
	else
	{
		if (signum == SIGUSR1)
			g_stor.atompacket = (g_stor.atompacket << 1) + BIT_OFF;
		else if (signum == SIGUSR2)
			g_stor.atompacket = (g_stor.atompacket << 1) + BIT_ON;
		if (++g_stor.recv_count == 8)
			ft_putchar_fd(g_stor.atompacket, STDOUT_FILENO);
	}
}

static void	reception(void)
{
	if (g_stor.pid == 0)
		pause();
	if (usleep(200) == 0)
	{
		g_stor.atompacket = 0;
		if (g_stor.recv_count == 0)
			g_stor.pid = 0;
		else if (g_stor.recv_count == 8)
			kill(g_stor.pid, COMM_SUC);
		else
			kill(g_stor.pid, COMM_ERR);
		g_stor.recv_count = 0;
	}
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
	g_stor.pid = 0;
	while (true)
		reception();
	return (0);
}

// #include <fcntl.h> //open

// static t_packet	g_stor;

// static void	ft_putbit_ft(unsigned int num, uint8_t size, int fd)
// {
// 	size *= 8;
// 	while (size--)
// 		ft_putchar_fd((num >> size & BIT_ON) + '0', fd);
// 	ft_putchar_fd('\n', fd);
// }

// static void	signal_handler(int signum, siginfo_t *info,
// 	void *ucontext __attribute__((unused)))
// {
// 	if (g_stor.pid == 0)
// 	{
// 		g_stor.pid = info->si_pid;
// 		kill(info->si_pid, COMM_SUC);
// 	}
// 	else if (g_stor.pid != info->si_pid)
// 		kill(info->si_pid, COMM_ERR);
// 	else
// 	{
// 		ft_putnbr_fd(g_stor.recv_count, g_stor.log_fd);
// 		ft_putstr_fd(":count\n", g_stor.log_fd);
// 		if (signum == SIGUSR1)
// 		{
// 			ft_putstr_fd("resive:0\n", g_stor.log_fd);
// 			g_stor.atompacket = (g_stor.atompacket << 1) + BIT_OFF;
// 		}
// 		else if (signum == SIGUSR2)
// 		{
// 			ft_putstr_fd("resive:1\n", g_stor.log_fd);
// 			g_stor.atompacket = (g_stor.atompacket << 1) + BIT_ON;
// 		}
// 		if (++g_stor.recv_count == 8)
// 		{
// 			ft_putchar_fd(g_stor.atompacket, STDOUT_FILENO);
// 			ft_putchar_fd(g_stor.atompacket, g_stor.log_fd);
// 			ft_putchar_fd(':', g_stor.log_fd);
// 			ft_putbit_ft(g_stor.atompacket, sizeof(char), g_stor.log_fd);
// 		}
// 	}
// }

// static void	reception(void)
// {
// 	while (true)
// 	{
// 		if (g_stor.pid == 0)
// 			pause();
// 		if (usleep(200) == 0)
// 		{
// 			g_stor.atompacket = 0;
// 			if (g_stor.recv_count == 0)
// 			{
// 				ft_putstr_fd("pid reset\n", g_stor.log_fd);
// 				g_stor.pid = 0;
// 			}
// 			else if (g_stor.recv_count == 8)
// 			{
// 				ft_putstr_fd("send:SUC\n", g_stor.log_fd);
// 				kill(g_stor.pid, COMM_SUC);
// 			}
// 			else
// 			{
// 				ft_putnbr_fd(g_stor.recv_count, g_stor.log_fd);
// 				ft_putstr_fd("-send:ERR\n", g_stor.log_fd);
// 				kill(g_stor.pid, COMM_ERR);
// 			}
// 			g_stor.recv_count = 0;
// 		}
// 	}
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
// 	g_stor.pid = 0;
// 	g_stor.log_fd = open("log/test.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	reception();
// 	ft_putstr_fd("\n--escape--\n", STDOUT_FILENO);
// 	close(g_stor.log_fd);
// 	return (0);
// }

	// buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (buffer == NULL)
	// 	return (0);

	// free(buffer);
