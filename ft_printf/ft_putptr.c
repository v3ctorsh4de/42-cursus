/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:17:52 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/10 00:34:27 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	count = 0;
	count += ft_putstr("0x");
	if (!ptr)
	{
		count += ft_putchar('0');
		return (count);
	}
	addr = (unsigned long)ptr;
	count += ft_puthex(addr, 0);
	return (count);
}
