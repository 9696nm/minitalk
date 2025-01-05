/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:24:08 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/12/21 18:18:46 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdint.h>
# include <signal.h>

# include "../libft/libft.h"

# if BUFFER_SIZE < 1 || 65535 < BUFFER_SIZE
#  undef BUFFER_SIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_packet
{
	int						log_fd;
	pid_t					pid;
	uint8_t					recv_count;
	volatile sig_atomic_t	atompacket;
}	t_packet;

typedef enum e_signal_command
{
	SIG_RETRY = 3,
	SIG_END = 0xFF
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
