/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:06:06 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/11 19:19:17 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	unsigned char	*b;
	size_t			i;

	b = (unsigned char *)buf;
	i = 0;
	while (i < count)
	{
		if (b[i] == (unsigned char)c)
			return ((b + i));
		i++;
	}
	return (NULL);
}
