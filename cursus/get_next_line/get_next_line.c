/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:15:10 by pbengoec          #+#    #+#             */
/*   Updated: 2022/11/03 15:04:04 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cut_string(char *s, int c)
{	
	char	*str;
	int		i;
	int		cont;

	i = 0;
	while (s[i] && (char)c != s[i])
		i++;
	if ((char)c == s[i])
	{
		i++;
		str = malloc(ft_strlen(s) - i * sizeof(char));
		if (str == NULL)
			return (NULL);
		cont = 0;
		printf("%zu\n",ft_strlen(s) + 1 - i);
		while (s[i])
			str[cont++] = s[i++];
		printf("%d",cont);
		str[cont] = '\0';
		free(s);
		return (str);
	}
	return (s);
}

static char	*ft_get_all(int fd, char *str)
{
	char	*buf;
	ssize_t	line;

	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buf == NULL)
		return (free(buf), NULL);
	line = 1;
	while (line > 0 || ft_strchr(buf, '\n'))
	{
		line = read(fd, buf, BUFFER_SIZE);
		if (line < 0)
			return (free(buf), free(str), NULL);
		if (line != 0)
		{
			buf[line] = '\0';
			str = ft_strjoin(str, buf);
		}
	}
	free(buf);
	return (str);
}

static char	*ft_get_first_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(i + 2 * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str == NULL)
		str = ft_get_all(fd, str);
	else{
		str = ft_cut_string (str, '\n');
	}
	if (str == NULL)
		return (NULL);
	line = ft_get_first_line(str);
	return (line);
}

int main()
{
	int fd;

	fd = open("hola.txt", O_RDONLY | O_CREAT);
	printf("LINEA VALOR: %s",get_next_line(fd));
	printf("\nLINEA VALOR: %s",get_next_line(fd));
	printf("\nLINEA VALOR: %s",get_next_line(fd));
	printf("\nLINEA VALOR: %s",get_next_line(fd));
	//get_next_line(fd);
}