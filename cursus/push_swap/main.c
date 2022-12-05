/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:43:41 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/05 20:58:45 by pbengoec         ###   ########.fr       */
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

int	ft_isvalid_str(char *str)
{
	int	i;

	i = 0;
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
		{
			ft_putstr_fd("Error\n", 2);
			return (255);
		}
	}
	return (0);
}
