/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:01:33 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/20 01:23:30 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t			n;
	static char		*stash;
	char			*buf;
	char			*line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (fd < 0)
		return (free(buf), NULL);
	n = read(fd, buf, BUFFER_SIZE);
	while (!ft_has_newline(stash) && n > 0)
	{
		buf[n] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	if (n < 0)
		return (free(stash), stash = NULL, NULL);
	line = ft_extract_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}
