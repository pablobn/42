/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:33:13 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/25 20:19:51 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*a;

	a = (char *) src;
	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (a[i] && i < dstsize - 1)
	{
		dst[i] = a[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;
	char	*a;

	a = (char *) src;
	size = ft_strlen(dst);
	i = 0;
	if (dstsize <= size)
		return (ft_strlen(src) + dstsize);
	while (src[i] && (size + i) < dstsize - 1)
	{
		dst[size + i] = src[i];
		i++;
	}
	dst[size + i] = '\0';
	return (size + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	sum;

	sum = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(sum * sizeof(char));
	if (new == 0)
		return (0);
	ft_strlcpy(new, s1, sum);
	ft_strlcat(new, s2, sum);
	new[sum] = '\0';
	return (new);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	
	copy = (char *) malloc(ft_strlen(s1) + 1);
	if (copy == 0)
		return (0);
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;
	size_t	memory;

	strlen = ft_strlen(s);
	memory = strlen + 1 - start;
	if (start > strlen || strlen == 0)
		return (ft_strdup(""));
	if (len + start < strlen + 1)
		memory = len + 1;
	else if (len == strlen + 1)
		memory = len;
	substr = malloc(memory * sizeof(char));
	if (substr == 0)
		return (0);
	ft_strlcpy(substr, &s[start], memory);
	return (substr);
}
