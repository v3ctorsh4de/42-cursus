/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:27:14 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/02 18:35:39 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *s, char c)
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
			while (s[i] & s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	unsigned char	**str;

	str = (unsigned char **)malloc
}
