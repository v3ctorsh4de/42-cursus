/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:19:40 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/14 19:28:18 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	safe_add(int *count, int ret)
{
	if (ret == -1)
		return (-1);
	*count += ret;
	return (0);
}

int	ft_putnbr(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		if (safe_add(&count, ft_putchar('-')) == -1)
			return (-1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		if (safe_add(&count, ft_putnbr(nbr / 10)) == -1)
			return (-1);
	if (safe_add(&count, ft_putchar((nbr % 10) + '0')) == -1)
		return (-1);
	return (count);
}
/*
int	main(void)
{
	ft_putnbr(25550404);
	return (0);
}
*/
