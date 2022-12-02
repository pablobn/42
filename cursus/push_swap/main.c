/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:43:41 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/02 19:39:36 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_node(t_stack **stack, int dato)
{
	t_stack	*new;
	new = malloc(sizeof(t_stack));
	new->value = dato;
	new->next = *stack;
	*stack = new;
}

void	show_node(t_stack *a)
{
	if (a == NULL)
		return ;
	printf("%d\n", a->value);
	show_node(a->next);
}

int	take_digit(char *str, t_stack **stack)
{
	int	i;
	int j;
	int flag;

	i = 0;
	flag = 1;
	while (str[i] == ' '|| str[i] == '\t' || str[i] == '\n')
		i++;
	j = i;
	while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n' && flag)
	{
		if (str[j] < '0' || str[j] > '9')
			flag = 0;
		j++;
	}
	if (flag)
	{
		printf("%d\n", flag);
		insert_node(stack, ft_atoi(&str[i]));
		if (str[j] != '\0')
			take_digit(&str[j], stack);
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack *a = NULL;
	int i;
	int valid;
	
	valid = 1;
	if (argc > 1)
	{
		i = 1;
		while (argv[i] && valid)
		{
			valid = take_digit(argv[i], &a);
			i++;
		}
		if (valid)
			show_node(a);
		else
			printf("Error\n");
	}
	return (0);
}