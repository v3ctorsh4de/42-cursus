/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:56:47 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/30 15:19:29 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
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

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		words;
	char	**str;

	words = ft_count_words(s, c);
	str = malloc(sizeof(*char) * words + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{

	}
	str[words + 1] = "\0";
}

int	main(void)
{
	ft_split("Hola    Mundo! aasdff", ' ');
	return (0);
}
