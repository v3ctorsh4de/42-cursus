/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:57:45 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/13 20:02:50 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_final_char(char c)
{
	char	*str;
	int		i;

	str = "csduxXp%";
	i = 0;
	while (str[i] && str[i] != c)
	{

	}
}

static int	dispatch(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		size += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		size += ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		size += ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == 'p')
		size += ft_putptr(va_arg(args, void *));
	else if (c == '%')
		size += ft_putchar('%');
	return (size);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += dispatch(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
