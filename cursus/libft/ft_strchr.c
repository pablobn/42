/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:56:42 by pbengoec          #+#    #+#             */
/*   Updated: 2022/09/22 17:33:43 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{	
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) &*s);
		s++;
	}
	if ((char)c == *s)
		return ((char *) &*s);
	return (NULL);
}

// int main()
// {
// 	printf("Function strchr str = \"teste\", char = 'e' \n");
// 	printf("Solution: %s\n",ft_strchr("teste", 'g'));
// }