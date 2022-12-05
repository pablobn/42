/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:43:41 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/05 21:18:44 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_bigger_int(char *str)
{
	int		i;
	size_t	len;
	char	*n;

	i = 0;
	n = "2147483648";
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[i] == '-')
			n = "2147483649";
		i++;
	}
	while (str[i] && str[i] == '0')
		i++;
	len = ft_strlen(&str[i]);
	if (len < 10)
		return (0);
	if (len == 10)
	{
		while (*n)
		{
			if (str[i] < *n)
				return (0);
			i++;
			n++;
		}
	}
	return (1);
}

int	ft_isvalid_str(char *str)
{
	int	i;

	i = 0;
	if (ft_bigger_int(str))
		return (1);
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	valid_digit(char *str, t_stack **stack)
{
	char	**split;
	int		i;

	split = ft_split(str, ' ');
	if (!split[0])
		return (free(split), 0);
	i = 0;
	while (split[i])
	{
		if (ft_isvalid_str(split[i]))
			return (free_split(split), 0);
		if (repetitive_node(stack, ft_atoi(split[i])))
			return (free_split(split), 0);
		insert_node(stack, ft_atoi(split[i]));
		i++;
	}
	return (free_split(split), 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		valid;

	valid = 1;
	a = NULL;
	if (argc > 1)
	{
		i = argc - 1;
		while (i >= 1 && valid)
		{
			valid = valid_digit(argv[i], &a);
			i--;
		}
		if (valid)
			show_node(a);
		else
			return (ft_putstr_fd("Error\n", 2), 255);
	}
	return (0);
}
