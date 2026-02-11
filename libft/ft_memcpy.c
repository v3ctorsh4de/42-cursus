/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:53:15 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/11 19:59:26 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dt;
	unsigned char	*sr;

	if (!dest && !src)
		return (NULL);
	dt = (unsigned char *)dest;
	sr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dt[i] = sr[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[10] = "test";
    char src[] = "nuevo";
    
    void *result = memcpy(dest, src, 0);
    
    printf("dest apunta a: %p\n", (void *)dest);
    printf("result apunta a: %p\n", result);
    printf("¿Son iguales? %s\n", (result == dest) ? "SÍ" : "NO");
    printf("Contenido de dest: %s\n", dest);  // Sigue siendo "test"
    
    return 0;
}
*/
