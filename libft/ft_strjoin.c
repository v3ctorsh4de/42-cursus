/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:09:59 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/29 17:27:45 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*concatenated_str;
	int			i;
	int			j;
	int			total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	concatenated_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (!concatenated_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concatenated_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		concatenated_str[i++] = s2[j];
		j++;
	}
	concatenated_str[i] = '\0';
	return (concatenated_str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "Hola, ";
	char	*s2 = "42 Madrid!";
	char	*resultado;

	// Test 1: Unión normal
	resultado = ft_strjoin(s1, s2);
	if (resultado)
	{
		printf("Resultado: |%s|\n", resultado);
		free(resultado); // ¡Importante liberar siempre el malloc!
	}
	else
		printf("Error: malloc falló o strings nulos.\n");

	// Test 2: Unir con un string vacío
	char *vacio = "";
	resultado = ft_strjoin(s1, vacio);
	printf("Test vacío: |%s|\n", resultado);
	free(resultado);

	return (0);
}
*/
