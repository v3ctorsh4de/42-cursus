/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:17:52 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/10 00:53:58 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ulong(unsigned long n, int uppercase)
{
	char	*hex_digits;
	int		count;

	count = 0;
	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_ulong(n / 16, uppercase);
	count += ft_putchar(hex_digits[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	addr = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex_ulong(addr, 0);
	return (count);
}
