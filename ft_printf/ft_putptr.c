/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:17:52 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/14 19:05:25 by jreyes-s         ###   ########.fr       */
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
		if (safe_add(&count, ft_puthex_ulong(n / 16, uppercase)) == -1)
			return (-1);
	if (safe_add(&count, ft_putchar(hex_digits[n % 16])) == -1)
		return (-1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	if (safe_add(&count, ft_putstr("0x")) == -1)
		return (-1);
	addr = (unsigned long)ptr;
	if (safe_add(&count, ft_puthex_ulong(addr, 0)) == -1)
		return (-1);
	return (count);
}
