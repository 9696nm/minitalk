/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:29:31 by hmori             #+#    #+#             */
/*   Updated: 2024/06/02 15:56:45 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	int	sing;

	sing = 1;
	if (-1 < nbr * sing)
		sing = -1;
	else
		ft_putchar_fd('-', 1);
	if (nbr * sing < -9)
		ft_putnbr_fd(nbr * sing / -10, fd);
	ft_putchar_fd((nbr * sing % 10) * -1 + '0', fd);
}

// int	main(void)
// {
// 	int	n = INT_MIN;

// 	ft_putnbr_fd(n, 0);
// 	return (0);
// }
