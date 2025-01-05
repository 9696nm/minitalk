/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:06:12 by hmori             #+#    #+#             */
/*   Updated: 2023/10/14 16:41:51 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}

// int	main(void)
// {
// 	int		fd = 1;
// 	char	*text = "abcd012";

// 	ft_putendl_fd(text, fd);
// 	return (0);
// }
