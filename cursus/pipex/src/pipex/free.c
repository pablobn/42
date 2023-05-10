/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:14:23 by pbengoec          #+#    #+#             */
/*   Updated: 2023/05/04 20:55:36 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_parent(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
}

void	ft_free_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_argv[i])
	{
		free(pipex->cmd_argv[i]);
		i++;
	}
	free(pipex->cmd_argv);
	free(pipex->cmd_path);
}
