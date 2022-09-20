/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:49:19 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/31 16:09:36 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 0)
	{
		nb *= ft_recursive_factorial(nb - 1);
		return (nb);
	}
	else if (nb == 0)
	{
		return (1);
	}
	return (0);
}
