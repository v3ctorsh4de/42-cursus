/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:25:08 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/14 22:25:10 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	size_t	len;
	int		result;

	if (argc != 3)
	{
		printf("Usage: %s string1 string2\n", argv[0]);
	}
	else
	{
		if	(strlen(argv[1]) < ft_strlen(argv[2]))
			len = ft_strlen(argv[1]);
		else
			len = ft_strlen(argv[2]);
		result = ft_memcmp(argv[1], argv[2], len);
		if (result == 0)
			printf("\"%s\" is identical to \"%s\"\n", argv[1], argv[2]);
		else if (result < 0)
			printf("\"%s\" is less than \"%s\"\n", argv[1], argv[2]);
		else
			printf("\"%s\" is greater than \"%s\"\n", argv[1], argv[2]);
		}
	}
*/
