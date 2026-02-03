/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:27:14 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/03 19:18:08 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while(s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*ft_save_strings(char const *s, size_t len)
{
	char	*str;
	size_t			i;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free_arr(char **arr, size_t words)
{
	while (words--)
		free(arr[words]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	word;
	size_t	words;
	char	**str;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	str = malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str[word] = ft_save_strings(s + start, i - start);
			if (!str[word])
			{
				ft_free_arr(str, word);
				return NULL;
			}
			word++;
		}
		else
			i++;
	}
	str[word] = NULL;
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
    size_t	words;
    char **arr = ft_split("Hola mundo en C", ' ');
    if (!arr)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Imprimir palabras
    for (size_t i = 0; arr[i]; i++)
    {
        printf("%s\n", arr[i]);
    }

    // Contar palabras
    words = 0;
    while (arr[words])
        words++;

    // Liberar memoria
    ft_free_arr(arr, words);
	return (0);
}
*/
