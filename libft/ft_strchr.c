/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:25:43 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/14 22:25:44 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	while (*string != '\0')
	{
		if (*string == (char)c)
			return ((char *)string);
		string++;
	}
	if ((char)c == '\0')
		return ((char *)string);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	buffer1[20] = "computer program";
	char	*ptr;
	int		ch;

	ch = 't';
	ptr = ft_strchr(buffer1, ch);
	printf("The first occurrence of %c in '%s' is '%s'\n",
			ch, buffer1, ptr);
}
*/
