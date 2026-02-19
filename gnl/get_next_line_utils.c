/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:22:04 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/02/19 03:10:57 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*tmp;
	int		i;
	int		j;

	tmp = s1;
	if (!s1)
		s1 = "";
	if (!s2)
		return (free(tmp), NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (free(tmp), NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	if (tmp)
		free(tmp);
	j = 0;
	while (s2[j])
		res[i + j] = s2[j++];
	res[i + j] = '\0';
	return (res);
}

int	ft_has_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	line = malloc(sizeof(char) * ft_strlen(stash) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			line[i] = stash[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*ft_update_stash(char *stash)
{

}
