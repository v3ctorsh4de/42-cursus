/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:00:41 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/22 20:50:14 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= *13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res * sign);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;

	str = argv[1];
	if (argc != 2)
	{
		printf("Usage: %s\n", argv[1]);
		return (1);
	}
	printf("%d\n", ft_atoi(str));
	return (0);
}
*/