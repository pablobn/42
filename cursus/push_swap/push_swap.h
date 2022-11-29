/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:32:25 by pbengoec          #+#    #+#             */
/*   Updated: 2022/11/29 17:44:46 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct stack
{
	int				value;
	struct stack	*next;
}t_stack;

void	ft_push_swap();
int		main(int argc, char **argv);

#endif