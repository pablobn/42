/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:15:17 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/20 18:57:22 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	res = 1;
	while (str[i] != '\0')
	{
		n = str[i];
		if (n >= 32 && n <= 126)
		{
			res = 1;
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (res);
}
