/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:36:58 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/04 17:18:51 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static unsigned int	g_stor[3];

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	if (g_stor[COUNT] == 0)
		g_stor[BIT] = 0;
	g_stor[PID] = info->si_pid;
	if (signum == SIGUSR1)
		g_stor[BIT] = (g_stor[BIT] << 1) + BIT_OFF;
	if (signum == SIGUSR2)
		g_stor[BIT] = (g_stor[BIT] << 1) + BIT_ON;
	if (++g_stor[COUNT] == 8)
		ft_putchar_fd(g_stor[BIT], STDOUT_FILENO);
	return ;
	if (ucontext == NULL)
		return ;
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
	g_stor[COUNT] = 0;
	while (1)
	{
		if (g_stor[COUNT] == 0)
			pause();
		if (usleep(200) == 0)
		{
			if (g_stor[COUNT] == 8)
				kill(g_stor[PID], COMM_SUC);
			else
				kill(g_stor[PID], COMM_ERR);
			g_stor[COUNT] = 0;
		}
	}
	return (0);
}

// #include <fcntl.h>

// static unsigned int	g_stor[4];

// static void	ft_putbit(unsigned int num, unsigned long int size)
// {
// 	size *= 8;
// 	while (size--)
// 		ft_putchar_fd((num >> size & BIT_ON) + '0', g_stor[3]); //STDOUT_FILENEO
// 	ft_putchar_fd('\n', g_stor[3]);
// }

// static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
// {
// 	g_stor[PID] = info->si_pid;
// 	if (signum == SIGUSR1)
// 		g_stor[BIT] = (g_stor[BIT] << 1) + BIT_OFF;
// 	if (signum == SIGUSR2)
// 		g_stor[BIT] = (g_stor[BIT] << 1) + BIT_ON;
// 	g_stor[COUNT]++;
// 	ft_putnbr_fd(g_stor[COUNT], g_stor[3]);
// 	ft_putchar_fd(':', g_stor[3]);
// 	ft_putbit(g_stor[BIT], sizeof(g_stor[BIT]));
// }

// static void	receipt(void)
// {
// 	if (g_stor[COUNT] == 0)
// 	{
// 		pause();
// 		ft_putstr_fd("conection\n", g_stor[3]);	
// 	}
// 	if (usleep(200))
// 		ft_putstr_fd("signal\n", g_stor[3]);
// 	else if (g_stor[COUNT] == 8)
// 	{
// 		ft_putchar_fd(g_stor[BIT], STDOUT_FILENO);
// 		g_stor[BIT] = 0;
// 		g_stor[COUNT] = 0;
// 		kill(g_stor[PID], COMM_SUC);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("timeout\n", g_stor[3]);
// 		g_stor[BIT] = 0;
// 		g_stor[COUNT] = 0;
// 		kill(g_stor[PID], COMM_ERR);
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
// 	g_stor[BIT] = 0;
// 	g_stor[COUNT] = 0;
// 	g_stor[3] = open("log/test.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	while (1)
// 		receipt();
// 	return (0);
// }
