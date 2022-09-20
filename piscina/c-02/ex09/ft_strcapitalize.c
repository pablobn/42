/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:03:48 by pbengoec          #+#    #+#             */
/*   Updated: 2022/08/24 14:15:49 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_mayuscula_primera(char *str)
{
	int	i;
	int	anterior;

	i = 0;
	anterior = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122 && anterior)
		{
			str[i] -= 32;
			anterior = 0;
		}	
		if (!(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 65 && str[i] <= 90))
		{
			if (str[i] >= 48 && str[i] <= 57)
				anterior = 0;
			else
				anterior = 1;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	ft_mayuscula_primera(str);
	return (str);
}
