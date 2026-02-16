/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:13:11 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/16 03:25:05 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 1024

char	*get_next_line(int fd)
{
	ssize_t	n;
	char	buf[BUF_SIZE];

	if (fd < 0)
		return (NULL);
	while ((n = read(fd, buf, BUF_SIZE)) > 0)
		ft_putchar(buf, n);
	if (n < 0)
		return (NULL);
	return ;
}
