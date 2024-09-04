/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:20:07 by hmori             #+#    #+#             */
/*   Updated: 2023/10/14 16:31:14 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*test;

	test = s;
	i = 0;
	while (i < size)
		test[i++] = c;
	return (test);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int		i = 2;
// 	char	s1[7] = {"absdefg"};

// 	memset(s1 + i, 'x', sizeof(s1) / sizeof(s1[0]) - i);
// 	// memset(s1 + 1, 45, 6);
// 	printf("%s\n", s1);
// 	return (0);
// }
