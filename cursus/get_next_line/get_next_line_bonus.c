/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:15:10 by pbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 17:20:43 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(int fd, char *str)
{
	ssize_t	size;
	char	*buf;

	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	if (size == -1)
		return (free(buf), free(str), NULL);
	buf[size] = '\0';
	while (size > 0 && !ft_strchr(buf, '\n'))
	{
		str = ft_strjoin(str, buf);
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
	}
	if (size == -1)
		return (free(buf), free(str), NULL);
	if (size > 0)
		str = ft_strjoin(str, buf);
	return (free(buf), str);
}

static char	*ft_cut_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(line), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_new_str(char *str)
{
	char	*new;
	int		i;
	int		j;

	if (!ft_strchr(str, '\n'))
		return (free(str), NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	i++;
	new = (char *) malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (free(new), NULL);
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	if (ft_strlen(new) == 0)
		return (free(new), free(str), NULL);
	return (free(str), new);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_get_line(fd, str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	line = ft_cut_line(str[fd]);
	str[fd] = ft_new_str(str[fd]);
	return (line);
}
