/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:56:40 by hmori             #+#    #+#             */
/*   Updated: 2023/10/14 16:22:21 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int		n;
// 	int		m;
// 	char	text[] = "Hello World";

// 	n = strlen(text);
// 	m = ft_strlen(text);
// 	printf("ord (%d), ft (%d)\n", n, m);
// 	return (0);
// }
