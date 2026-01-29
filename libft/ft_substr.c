/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:34:23 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/29 17:08:15 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && (i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

#include <stdio.h>
int	main(void)
{
	char	*str = "Hola Mundo";
	char	*res;

	// Test 1: Caso normal
	res = ft_substr(str, 5, 5);
	printf("Test 1 (Mundo): %s\n", res);
	free(res);

	// Test 2: Start fuera de rango
	res = ft_substr(str, 20, 5);
	printf("Test 2 (Vacío): [%s]\n", res);
	free(res);

	// Test 3: Len más grande que el string
	res = ft_substr(str, 0, 50);
	printf("Test 3 (Hola Mundo): %s\n", res);
	free(res);

	return (0);
}
