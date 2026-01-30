/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42.com>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:32:03 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/14 12:36:56 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int	len;

	len = 0;
	while (string[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (string[len] == (char)c)
			return ((char *)string + len);
		len--;
	}
	return (NULL);
}
/*#include <stdio.h>

int	main(void)
{
	char buf[20] = "computer program";
	char *ptr;

	int ch = 't';
	ptr = strrchr(buf, ch);

}*/
