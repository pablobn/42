/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:32:25 by pbengoec          #+#    #+#             */
/*   Updated: 2022/12/19 15:02:57 by pbengoec         ###   ########.fr       */
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
	int				position;
	int				current;
	int				move;
	int				calc;
	int				dir;
	int				other_move;
	int				other_dir;
	struct stack	*next;
}t_stack;

void	ft_push_swap(t_stack **a);
int		main(int argc, char **argv);
void	insert_node(t_stack **stack, int dato);
int		repetitive_node(t_stack **stack, int dato);
void	show_node(t_stack *a);
void	ft_swap(t_stack **a, int num);
int		ft_list_size(t_stack **a);
void	ft_rotate(t_stack **a, int num);
void	ft_reverse_rotate(t_stack **a, int num);
void	ft_push_list(t_stack **a, t_stack **b, int num);
void	ft_order_array(int *ar, int size);
void	ft_order_list(t_stack **a, int *ar);
void	ft_give_index(t_stack **a);
void	ft_give_current_place(t_stack *a);
void	ft_give_direction(t_stack **c);
void	ft_calcular_movimientos(t_stack **a, t_stack *b);
int		valid_list(t_stack **a);
#endif