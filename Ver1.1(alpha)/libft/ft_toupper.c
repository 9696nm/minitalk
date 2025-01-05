/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:41 by hmori             #+#    #+#             */
/*   Updated: 2023/10/24 15:03:40 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int num)
{
	if ('a' <= num && num <= 'z')
		return (num + ('A' - 'a'));
	return (num);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	set[4] = {'B', 86, 'r', ','};

// 	for (int i = 0; i < 4; i++)
// 		printf("%c\n", ft_toupper(set[i]));
// 	return (0);
// }
