/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:24:08 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/07 21:42:10 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdint.h>
# include <signal.h>
# include <stdbool.h>

# include "../libft/libft.h"

typedef struct s_packet
{
	pid_t					pid;
	uint8_t					recv_count;
	volatile sig_atomic_t	atompacket;
}	t_packet;

typedef enum e_signal_command
{
	SIG_RETRY = 3
}	t_sigcmd;

typedef enum e_bit_state
{
	BIT_OFF = 0,
	BIT_ON = 1
}	t_bits;

typedef enum e_signal_state
{
	COMM_SUC = SIGUSR1,
	COMM_ERR = SIGUSR2
}	t_sigstate;

#endif

// typedef struct s_packet
// {
// 	int						log_fd;
// 	pid_t					pid;
// 	uint8_t					recv_count;
// 	volatile sig_atomic_t	atompacket;
// }	t_packet;
