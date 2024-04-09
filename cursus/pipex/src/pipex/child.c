/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:48:16 by pbengoec          #+#    #+#             */
/*   Updated: 2024/01/24 18:53:55 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_get_cmd(t_pipex pipex, char *str)
{
	char	**cases;
	char	*tmp;
	int		i;

	cases = ft_split(pipex.path, ':');
	i = 0;
	while (cases[i])
	{
		tmp = ft_strjoin(cases[i], str);
		if (access(tmp, 0) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_first_process(char **argv, char **envp, t_pipex pipex)
{
	dup2(pipex.tube[1], STDOUT_FILENO);
	close(pipex.tube[0]);
	dup2(pipex.infile, STDIN_FILENO);
	pipex.cmd_argv = ft_split(argv[2], ' ');
	pipex.cmd_path = ft_get_cmd(pipex, ft_strjoin("/", pipex.cmd_argv[0]));
	if (!pipex.cmd_path)
	{
		ft_msg_child_error("'");
		ft_msg_child_error(argv[2]);
		ft_msg_child_error("' No existe tal comando\n");
		ft_free_child(&pipex);
		exit(1);
	}
	execve(pipex.cmd_path, &argv[2], envp);
}

void	ft_second_process(char **argv, char **envp, t_pipex pipex)
{
	dup2(pipex.tube[0], STDIN_FILENO);
	close(pipex.tube[1]);
	dup2(pipex.outfile, STDOUT_FILENO);
	pipex.cmd_argv = ft_split(argv[3], ' ');
	pipex.cmd_path = ft_get_cmd(pipex, ft_strjoin("/", pipex.cmd_argv[0]));
	if (!pipex.cmd_path)
	{
		ft_msg_child_error("'");
		ft_msg_child_error(argv[3]);
		ft_msg_child_error("' No existe tal comando\n");
		ft_free_child(&pipex);
		exit(1);
	}
	execve(pipex.cmd_path, &argv[3], envp);
}
