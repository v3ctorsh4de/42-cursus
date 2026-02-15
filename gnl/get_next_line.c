/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:13:11 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/15 03:32:44 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 1024

char	*get_next_line(int fd)
{
	int		fd;
	size_t	n;
	char	*buf[BUF_SIZE];

	fd = open("libro.txt", O_RDONLY);
	while ((n = read(fd, buf, BUF_SIZE)) > 0)
	{
		ft_putstr();
	}
	close(fd);
}
