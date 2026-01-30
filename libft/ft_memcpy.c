/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:53:15 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/30 02:55:12 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dt;
	unsigned char	*sr;

	if (!dest || !src)
		return (NULL);
	dt = dest;
	sr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dt[i] = sr[i];
		i++;
	}
	return (dt);
}
