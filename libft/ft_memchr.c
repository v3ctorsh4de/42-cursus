/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:06:06 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/20 13:33:27 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *buf, int c, size_t count)
{
    unsigned char *b;
    size_t i;

    b = (unsigned char *)buf;
    i = 0;
    if (buf == NULL || count == 0)
        return (NULL);
    while (i < count)
    {
        if (b[i] == (unsigned char)c)
            return ((b + i));
        i++;
    }
    return (NULL);
}
#include <stdio.h>

int main(int argc, char **argv)
{
    char *result;

    if (argc != 2)
    {
        printf("Usage: %s string\n", argv[0]);
        return (0);
    }
    if ((result = (char *)ft_memchr(argv[1], 'x', ft_strlen(argv[1]))) != NULL)
        printf("The string starting with x is %s\n", result);
    else
        printf("The letter x cannot be found in the string\n");
    return (0);
}
