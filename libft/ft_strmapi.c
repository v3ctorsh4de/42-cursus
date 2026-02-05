/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:28:45 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/05 14:25:51 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*p;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = (char *)s;
	p = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		p[i] = f(i, str[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
#include <stdio.h>

char	f(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

int	main(void)
{
	char	*s;

	s = ft_strmapi("hola 42", f);
	printf("%s\n", s);
	free(s);
}
*/
