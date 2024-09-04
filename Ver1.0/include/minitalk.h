/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:24:08 by hana/hmori        #+#    #+#             */
/*   Updated: 2024/09/04 19:34:02 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdint.h>
# include <signal.h>

# include "../libft/libft.h"

typedef enum e_bit_state
{
	BIT_ON = 1,
	BIT_OFF = 0
}	t_bits;

typedef enum e_signal_state
{
	COMM_SUC = SIGUSR1,
	COMM_ERR = SIGUSR2
}	t_sigs;

typedef enum e_storage_name
{
	BIT = 0,
	COUNT = 1,
	PID = 2
}	t_stor;

#endif
