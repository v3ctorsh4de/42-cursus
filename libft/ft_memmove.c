/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:29:02 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/30 13:23:31 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tdest;
	unsigned char	*tsrc;

	tdest = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	if (dst == src || n == 0)
		return (dst);
	if (tsrc < tdest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			tdest[i] = tsrc[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			tdest[i] = tsrc[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hola mundo";

	printf("Antes: '%s'\n", str);
	ft_memmove(str + 2, str, 5);
	printf("Tuya:  '%s'\n", str);
	return (0);
}
*/
