/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:57:12 by hmori             #+#    #+#             */
/*   Updated: 2023/10/02 15:22:22 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int num)
{
	if ('A' <= num && num <= 'Z')
		return (num + ('a' - 'A'));
	return (num);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	set[4] = {'B', 86, 'r', ','};

// 	for (int i = 0; i < 4; i++)
// 		printf("%c\n", ft_tolower(set[i]));
// 	return (0);
// }
