/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:34:38 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/12 21:17:27 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s = (unsigned char *)src;
	unsigned char		*d;

	if (!src && !dst)
		return (NULL);
	d = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strdup(const char *str)
{
	unsigned char	*s;

	s = (unsigned char *)malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	s = (unsigned char *)ft_memcpy(s, str, ft_strlen(str) + 1);
	return ((char *)s);
}

int	ft_letterpos(const char *str, int letter)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if ((int)str[i] == letter)
			return (i);
		i++;
	}
	if ((letter == EOF) && i != BUFFER_SIZE - 1)
		return (i);
	return (-1);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	i;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return ((char *)substr);
	}
	if (((size_t)start + len) > str_len)
		len = str_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i++ < len)
		substr[i - 1] = str[i - 1 + start];
	substr[i - 1] = '\0';
	return ((char *)substr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t				src_len;
	size_t				i;
	const unsigned char	*s = (unsigned char *)src;
	unsigned char		*d;

	src_len = ft_strlen (src);
	if (size > 0)
	{
		d = (unsigned char *)dst;
		i = 0;
		while ((i < size - 1) && (s[i] != '\0'))
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const unsigned char	*s = (unsigned char *)src;
	unsigned char		*d;
	size_t				dst_len;
	size_t				src_len;
	size_t				i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (size + src_len);
	if (size != 0)
	{
		d = (unsigned char *)dst;
		i = 0;
		while ((dst_len + i < size - 1) && (s[i] != 0))
		{
			d[dst_len + i] = s[i];
			i++;
		}
		d[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, s1_len + 1);
	ft_strlcat(dst, s2, s1_len + s2_len + 1);
	return (dst);
}
