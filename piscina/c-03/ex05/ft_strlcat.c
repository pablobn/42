/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:30:54 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/25 16:06:40 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;

	if (dest[size - 1] == '\0')
		size--;
	j = 0;
	while (src[j] != '\0')
	{
		dest[size] = src[j];
		size++;
		j++;
	}
	return (size);
}
