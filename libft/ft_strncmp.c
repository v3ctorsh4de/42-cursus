/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:00:43 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/15 12:57:33 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *string1, const char *string2, size_t count)
{
    size_t i;

    i = 0;
    while (i < count && string1[i] == string2[i])
    {
        if (string1[i] == '\0')
            return (0);
        i++;
    }
    if (i == count)
        return (0);
    return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    int result;
    int index = 3;
    char buffer1[20] = "aabcdefg";
    char buffer2[20] = "abcfg";

    result = ft_strncmp(buffer1, buffer2, index);
    printf("\nComparison of only the first %i characters\n", index);
    printf("  ft_strncmp: ");
    printf("%d\n", result);

    result = strncmp(buffer1, buffer2, index);
    printf("\nComparison of only the first %i characters\n", index);
    printf("  strncmp: ");
    printf("%d\n", result);
}
*/