/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:55:49 by pbengoec          #+#    #+#             */
/*   Updated: 2023/05/17 17:09:20 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_msg_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(1);
}

int	ft_msg_child_error(char *err)
{
	ft_putstr_fd(err, 2);
	return (0);
}
