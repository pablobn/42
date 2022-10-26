/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:15:10 by pbengoec          #+#    #+#             */
/*   Updated: 2022/10/25 20:31:47 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_word(int fd)
{
	ssize_t		line;
	char		*buf;

	buf = malloc(BUFFER_SIZE * sizeof(char) + 1);
	line = read(fd, buf, BUFFER_SIZE);
	if (line <= 0)
		return (free(buf),NULL);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	int			i;
	int			flag;
	char 		*cpy;

	flag = 1;
	if (buf == NULL)
		buf = ft_strdup("");
	while (flag)
	{
		//si read devuelve 0 es el fin de archivo
		buf = ft_strjoin(buf,get_next_word(fd));
		cpy = ft_strdup(buf);
		i = 0;
		while (cpy[i])
		{
			if (cpy[i] == '\n')
			{
				buf = ft_substr(buf,i + 1,ft_strlen(buf));
				return (ft_substr(cpy,0,i + 1));
			}
			i++;
		}
	}
	return (buf);
}

int main()
{
	int fd;

	fd = open("hola.txt", O_RDONLY | O_CREAT);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}