/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:36:58 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/04 14:46:15 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

#include <fcntl.h> //open

static t_packet	g_stor;

static void	ft_putbit_ft(unsigned int num, uint8_t size, int fd)
{
	size *= 8;
	while (size--)
		ft_putchar_fd((num >> size & BIT_ON) + '0', fd);
	ft_putchar_fd('\n', fd);
}

static void	signal_handler(int signum, siginfo_t *info, void *ucontext __attribute__((unused)))
{
	if (g_stor.pid == 0)
	{
		g_stor.pid = info->si_pid;
		g_stor.recv_count = 0;
		kill(info->si_pid, COMM_SUC);
	}
	else if (g_stor.pid != info->si_pid)
		kill(info->si_pid, COMM_ERR);
	else
	{
		if (g_stor.recv_count == 0)
			g_stor.atompacket = 0;
		if (signum == SIGUSR1)
		{
			ft_putstr_fd("resive:0\n", g_stor.log_fd);
			g_stor.atompacket = (g_stor.atompacket << 1) + BIT_OFF;
		}
		else if (signum == SIGUSR2)
		{
			ft_putstr_fd("resive:1\n", g_stor.log_fd);
			g_stor.atompacket = (g_stor.atompacket << 1) + BIT_ON;
		}
		g_stor.recv_count++;
	}
}

static void	reception(void)
{
	while (g_stor.pid || sleep(600)) 
	{
		if (usleep(100) == 0 && g_stor.recv_count < 8)
		{
			g_stor.recv_count = 0;
			ft_putnbr_fd(g_stor.recv_count, g_stor.log_fd);
			ft_putstr_fd("-send:ERR\n", g_stor.log_fd);
			kill(g_stor.pid, COMM_ERR);
		}
		else if (g_stor.recv_count == 8)
		{
			if (g_stor.atompacket == SIG_END)
				g_stor.pid = 0;
			else
			{	
				ft_putchar_fd(g_stor.atompacket, STDOUT_FILENO);
				ft_putchar_fd(g_stor.atompacket, g_stor.log_fd);
				ft_putchar_fd(':', g_stor.log_fd);
				ft_putbit_ft(g_stor.atompacket, sizeof(char), g_stor.log_fd);
			}
			g_stor.recv_count = 0;
			ft_putstr_fd("send:SUC\n", g_stor.log_fd);
			kill(g_stor.pid, COMM_SUC);
		}
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
	g_stor.log_fd = open("log/test.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	reception();
	ft_putstr_fd("\n--escape--\n", STDOUT_FILENO);
	close(g_stor.log_fd);
	return (0);
}

	// buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (buffer == NULL)
	// 	return (0);

	// free(buffer);


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
// 	packet.pid = info->si_pid;
// 	if (signum == SIGUSR1)
// 		packet.packet = (packet.packet << 1) + BIT_OFF;
// 	if (signum == SIGUSR2)
// 		packet.packet = (packet.packet << 1) + BIT_ON;
// 	packet.recv_count++;
// 	ft_putnbr_fd(packet.recv_count, g_stor[3]);
// 	ft_putchar_fd(':', g_stor[3]);
// 	ft_putbit(packet.packet, sizeof(packet.packet));
// 	return ;
// 	if (ucontext == NULL)
// 		return ;
// }

// static void	receipt(void)
// {
// 	if (packet.recv_count == 0)
// 	{
// 		pause();
// 		ft_putstr_fd("conection\n", g_stor[3]);	
// 	}
// 	if (usleep(200))
// 		ft_putstr_fd("signal\n", g_stor[3]);
// 	else if (packet.recv_count == 8)
// 	{
// 		ft_putchar_fd(packet.packet, STDOUT_FILENO);
// 		packet.packet = 0;
// 		packet.recv_count = 0;
// 		kill(packet.pid, COMM_SUC);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("timeout\n", g_stor[3]);
// 		packet.packet = 0;
// 		packet.recv_count = 0;
// 		kill(packet.pid, COMM_ERR);
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
// 	packet.packet = 0;
// 	packet.recv_count = 0;
// 	g_stor[3] = open("log/test.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	while (1)
// 		receipt();
// 	return (0);
// }
