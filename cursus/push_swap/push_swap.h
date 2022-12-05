/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:32:25 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/05 20:54:51 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct stack
{
	int				value;
	struct stack	*next;
}t_stack;

void	ft_push_swap(void);
int		main(int argc, char **argv);
void	insert_node(t_stack **stack, int dato);
int		repetitive_node(t_stack **stack, int dato);
void	show_node(t_stack *a);
#endif