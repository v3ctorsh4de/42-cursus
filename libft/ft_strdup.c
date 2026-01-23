/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 02:08:27 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/23 02:21:02 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
#include <stdio.h>
#include <string.h>

// Prototipo de tu función (si no incluyes tu libft.h)
char	*ft_strdup(const char *s);

int	main(void)
{
	char	*original = "Hola Mundo 42!";
	char	*copia;

	printf("--- Test ft_strdup ---\n");
	printf("Original: %s (Dirección: %p)\n", original, (void *)original);

	// 1. Ejecutamos tu función
	copia = ft_strdup(original);

	// 2. Verificamos si malloc falló
	if (copia == NULL)
	{
		printf("Error: Fallo en la asignación de memoria.\n");
		return (1);
	}

	// 3. Mostramos la copia y su dirección de memoria
	printf("Copia:    %s (Dirección: %p)\n", copia, (void *)copia);

	// 4. Prueba de independencia
	// Si modificamos la copia, el original NO debe cambiar
	copia[0] = 'X';
	printf("\n--- Después de modificar la copia ---\n");
	printf("Original: %s\n", original);
	printf("Copia:    %s\n", copia);

	// 5. ¡Súper importante! Liberar la memoria
	free(copia);
	printf("\nMemoria liberada correctamente.\n");

	return (0);
}
*/
