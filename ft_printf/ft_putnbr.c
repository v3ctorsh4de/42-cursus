/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:19:40 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/14 16:42:45 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nbr;
	int		count;
	int		tmp;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		tmp = ft_putnbr(nbr / 10);
		if (tmp == -1)
			return (-1);
		count++;
	}
	if (ft_putchar((nbr % 10) + '0') == -1)
		return (-1);
	return (count + 1);
}
/*
int	main(void)
{
	ft_putnbr(25550404);
	return (0);
}
*/
