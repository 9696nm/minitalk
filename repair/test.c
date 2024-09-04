/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:03:47 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/04 02:08:16 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include <stdio.h>

static void	ft_putbit(unsigned int num, unsigned long size)
{
	size *= 8;
	while (size--)
		ft_putchar_fd((num >> size & BIT_ON) + '0', STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	signal_handler(int signum)
{
	;
}

int	main(void)
{
	int	i;

	ft_putstr_fd(ft_itoa(getpid()), STDOUT_FILENO);
	signal(SIGUSR1, signal_handler);
	i = 0b01001;
	if (sleep(20))
		ft_putstr_fd("chancel", 1);
	else
		ft_putbit(i, sizeof(uint8_t));
	// printf("%d\n", i >> 1 & 1);
	return (0);
}