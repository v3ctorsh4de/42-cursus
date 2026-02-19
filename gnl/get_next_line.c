/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:01:33 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/19 02:01:22 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 42

char	*get_next_line(int fd)
{
	ssize_t		n;
	static int	i;
	char		*stash;
	char		*buf;

	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!buf || fd < 0)
		return (NULL);
	while ((n = read(fd, buf, BUF_SIZE)) > 0)
	{
		tmp = ft_strjoin(stash, buf);
		free(stash);
		stash = tmp;
		i = 0;
		while (stash[i])
		{
			if (stash[i] == '\n')
				return (stash);
			else
				i++;
		}
	}
	if (n < 0)
		return (NULL);
}
