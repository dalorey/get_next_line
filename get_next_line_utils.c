/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:34:38 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/16 11:13:44 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *src, int c)
{
	const unsigned char	*s = (unsigned char *)src;
	int					i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	i;
	size_t	n;

	dst = (char *)malloc(ft_strlen(src) + 1);
	if (!src || !dst)
		return (NULL);
	i = -1;
	n = ft_strlen(src) + 1;
	while (++i < n)
		dst[i] = src[i];
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
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
		substr = (char *)malloc(1);
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
	i = -1;
	while (++i < len)
		substr[i] = str[i + start];
	substr[i] = '\0';
	return ((char *)substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*dst;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *)malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		dst[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		dst[i + s1_len] = s2[i];
	dst[i + s1_len] = '\0';
	return (dst);
}
