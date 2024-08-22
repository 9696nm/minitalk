/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmori <hmori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:32:00 by hmori             #+#    #+#             */
/*   Updated: 2024/05/20 12:25:12 by hmori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_on_pchar(int nbr, char *res, size_t len)
{
	res[len] = -1 * (nbr % 10) + '0';
	if (!(nbr > -10))
		put_on_pchar(nbr / 10, res, --len);
}

static size_t	about_len(int nbr, int *sing)
{
	size_t	len;

	len = 1;
	*sing = 1;
	if (nbr < 0)
	{
		*sing *= -1;
		len++;
	}
	while (nbr < -9 || 9 < nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		sing;
	size_t	len;
	char	*res;

	len = about_len(nbr, &sing);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (sing == -1)
		*res = '-';
	put_on_pchar(nbr * sing * -1, res, len - 1);
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int		n = INT_MIN;
// 	char	*res;

// 	res = ft_itoa(n);
// 	// printf("%s\n", res);
// 	free(res);
// 	return (0);
// }
