/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:43:41 by pbengoec          #+#    #+#             */
/*   Updated: 2023/01/16 13:22:16 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_change_sign(char *str, char **n, int *i)
{
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[*i] == '-')
			n[0] = "2147483649";
		*i = 1;
	}
}

int	ft_bigger_int(char *str)
{
	int		i;
	size_t	len;
	char	*n;

	i = 0;
	n = "2147483648";
	ft_change_sign(str, &n, &i);
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
		i++;
	i--;
	while (i >= 0)
	{
		if (ft_isvalid_str(split[i]))
			return (free_split(split), 0);
		if (repetitive_node(stack, ft_atoi(split[i])))
			return (free_split(split), 0);
		insert_node(stack, ft_atoi(split[i]));
		i--;
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
			ft_push_swap(&a);
		else
			return (ft_putstr_fd("Error\n", 2), 255);
	}
	return (free_list(a),0);
}
