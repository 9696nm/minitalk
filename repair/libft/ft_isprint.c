/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:11:49 by hmori             #+#    #+#             */
/*   Updated: 2023/10/14 15:08:41 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int num)
{
	return (32 <= num && num <= 126);
}

/*returnについてはdigit参照*/

// #include <stdio.h>
// #include <ctype.h>
// #include <limits.h>

// int	main(void)
// {
// 	for (int i = 0; i < UCHAR_MAX + 1; i++)
// 	{
// 		if (isprint(i))
// 			printf("%c (%d)\n", i, i);
// 	}
// 	return (0);
// }
