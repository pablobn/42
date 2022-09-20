/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:15:17 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/20 18:51:21 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	res = 1;
	while (str[i] != '\0')
	{
		n = str[i];
		if (n >= 65 && n <= 90)
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
