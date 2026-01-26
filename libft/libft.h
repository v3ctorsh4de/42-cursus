/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jreyes-s <jreyes-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:52:31 by jreyes-s          #+#    #+#             */
/*   Updated: 2026/01/26 18:56:48 by jreyes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

int				ft_isalpha(int c);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *string, int c);
char			*ft_strrchr(const char *string, int c);
int				ft_strncmp(const char *string1, const char *string2,
					size_t count);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *buf, int c, size_t count);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
int				ft_atoi(const char *str);

#endif
