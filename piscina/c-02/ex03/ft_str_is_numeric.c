/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:25:56 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/20 17:13:25 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	res = 1;
	while (str[i] != '\0')
	{
		n = str[i];
		if (n >= 48 && n <= 57)
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
