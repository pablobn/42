/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:31:07 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/31 16:09:06 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	if (nb > 0)
	{
		while (i <= nb)
		{
			res *= i;
			i++;
		}
		return (res);
	}
	else if (nb == 0)
	{
		return (1);
	}
	return (0);
}
