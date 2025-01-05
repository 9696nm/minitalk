/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:56:00 by hmori             #+#    #+#             */
/*   Updated: 2023/11/09 18:31:09 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	while (size-- > 0)
		((unsigned char *)s)[size] = '\0';
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	int		i = 2;
// 	char	s1[8] = {"absdefg"};

// 	ft_bzero(s1 + i, ft_strlen(s1 + i));
// 	printf("%s\n", s1);
// 	return (0);
// }
