/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:24:08 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/16 19:03:07 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdint.h>
# include <signal.h>

# include "../libft/libft.h"

typedef struct s_packet
{
	pid_t					pid;
	uint8_t					recv_count;
	volatile sig_atomic_t	packet;
}	t_packet;

typedef enum e_bit_state
{
	BIT_OFF = 0,
	BIT_ON = 1
}	t_bits;

typedef enum e_signal_state
{
	COMM_SUC = SIGUSR1,
	COMM_ERR = SIGUSR2
}	t_sigs;

typedef enum e_signal_parameter_micro_second
{
	EXT_EARLY = 20,
	MAX_WAIT_TIME = 70,
	SIGNAL_INTERVAL = 50,
	PID_DETECTION = MAX_WAIT_TIME * 20
}	t_sigparam_us;

#endif
