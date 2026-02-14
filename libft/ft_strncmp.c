/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:26:59 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/14 22:27:00 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count && string1[i] == string2[i])
	{
		if (string1[i] == '\0')
			return (0);
		i++;
	}
	if (i == count)
		return (0);
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		result;
	int		index;
	char	buffer1[20] = "aabcdefg";
	char	buffer2[20] = "abcfg";

	index = 3;
	result = ft_strncmp(buffer1, buffer2, index);
	printf("\nComparison of only the first %i characters\n", index);
	printf("  ft_strncmp: ");
	printf("%d\n", result);
	result = strncmp(buffer1, buffer2, index);
	printf("\nComparison of only the first %i characters\n", index);
	printf("  strncmp: ");
	printf("%d\n", result);
}
*/
