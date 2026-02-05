/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:21:59 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/03 20:16:16 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_numlen(nbr);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	// Caso positivo
	result = ft_itoa(42);
	printf("42 -> %s\n", result);
	free(result);
	// Caso negativo
	result = ft_itoa(-123);
	printf("-123 -> %s\n", result);
	free(result);
	// Cero
	result = ft_itoa(0);
	printf("0 -> %s\n", result);
	free(result);
	// INT_MIN (caso difícil)
	result = ft_itoa(-2147483648);
	printf("-2147483648 -> %s\n", result);
	free(result);
	return (0);
}
*/
