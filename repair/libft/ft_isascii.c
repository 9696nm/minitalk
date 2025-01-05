/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:07:22 by hmori             #+#    #+#             */
/*   Updated: 2023/10/14 15:07:18 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int num)
{
	return (0 <= num && num <= 127);
}

// #include <stdio.h>
// #include <ctype.h>
// #include <limits.h>

// int	main(void)
// {
// 	for (int i = 0; i < UCHAR_MAX + 1; i++)
// 	{
// 		if (ft_isascii(i))
// 			printf("%c (%d)\n", i, i);
// 	}
// 	return (0);
// }
