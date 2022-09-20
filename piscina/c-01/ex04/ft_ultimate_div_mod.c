/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:04:08 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/27 16:01:05 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	resultado;
	int	resto;

	resultado = *a / *b;
	resto = *a % *b;
	*a = resultado;
	*b = resto;
}
