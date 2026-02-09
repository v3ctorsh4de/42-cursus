/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:28:32 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/09 21:49:08 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr >= 10)
		count += ft_putnbr_unsigned(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}
/*
int	main(void)
{
	ft_putnbr_unsigned(233283283);
	return (0);
}
*/
