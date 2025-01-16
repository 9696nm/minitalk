/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:03:47 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/16 18:42:26 by hana/hmori       ###   ########.fr       */
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

	ft_putbit('U', sizeof(uint8_t));
	ft_putbit('e', sizeof(uint8_t));
	ft_putbit('Y', sizeof(uint8_t));
	ft_putbit('S', sizeof(uint8_t));
	ft_putbit('V', sizeof(uint8_t));
	return (0);
}

