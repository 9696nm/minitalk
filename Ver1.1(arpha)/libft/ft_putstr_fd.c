/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:47:22 by hmori             #+#    #+#             */
/*   Updated: 2024/06/02 15:56:57 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	while (INT_MAX < len)
	{
		write(fd, str, INT_MAX);
		str += INT_MAX;
		len -= INT_MAX;
	}
	write(fd, str, len);
}

// #include <stdlib.h>
// #include <limits.h>

// int	main(void)
// {
// 	int		fd = 0;
// 	char	*text = "abcd012";

// 	ft_putstr_fd(text, fd);
// 	return (0);
// }
