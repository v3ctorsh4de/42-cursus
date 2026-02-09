/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:51:22 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/09 21:23:05 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(char const *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsig(unsigned int n);
int	ft_printf_hexa(unsigned int nbr, char upper);
int	ft_printf_ptr(void *ptr);

#endif // !FT_PRINTF_H
