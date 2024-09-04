/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:01:02 by hmori             #+#    #+#             */
/*   Updated: 2023/10/14 15:08:22 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int num)
{
	return (ft_isdigit(num) || ft_isalpha(num));
}

/*returnについてはdigit参照*/

// #include <stdio.h>
// #include <ctype.h>
// #include <limits.h>

// int	main(void)
// {
// 	for (int i = 0; i < UCHAR_MAX + 1; i++)
// 	{
// 		if (ft_isalnum(i))
// 			printf("%c (%d)\n", i, i);
// 	}
// 	return (0);
// }
