/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 02:31:26 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/21 14:36:33 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hays;
	char	*need;

	hays = (char *)haystack;
	need = (char *)needle;
	if (*need == '\0')
		return (hays);
	i = 0;
	while (hays[i] && (i < len))
	{
		j = 0;
		while (need[j] && (hays[i + j] == need[j] && ((j + i) < len)))
			j++;
		if (need[j] == '\0')
			return (hays + i);
		i++;
	}
	return (NULL);
}

#include <stdio.h>

int main(void)
{
    const char *haystack;
    const char *needle;
    char *result;
    size_t len;

    // Test 1: needle dentro de haystack
    haystack = "hola mundo";
    needle = "mundo";
    len = 10;
    result = ft_strnstr(haystack, needle, len);
    printf("Test 1: %s\n", result ? result : "NULL"); // Esperado: "mundo"

    // Test 2: needle no cabe dentro de len
    haystack = "hola mundo";
    needle = "mundo";
    len = 4;
    result = ft_strnstr(haystack, needle, len);
    printf("Test 2: %s\n", result ? result : "NULL"); // Esperado: "NULL"

    // Test 3: needle vacío
    haystack = "hola mundo";
    needle = "";
    len = 5;
    result = ft_strnstr(haystack, needle, len);
    printf("Test 3: %s\n", result ? result : "NULL"); // Esperado: "hola mundo"

    // Test 4: needle más largo que haystack
    haystack = "abc";
    needle = "abcd";
    len = 4;
    result = ft_strnstr(haystack, needle, len);
    printf("Test 4: %s\n", result ? result : "NULL"); // Esperado: "NULL"

    // Test 5: needle al final de len exacto
    haystack = "abcd";
    needle = "cd";
    len = 4;
    result = ft_strnstr(haystack, needle, len);
    printf("Test 5: %s\n", result ? result : "NULL"); // Esperado: "cd"

    return (0);
}
