/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:15:59 by pbengoec          #+#    #+#             */
/*   Updated: 2024/01/17 15:48:03 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../library/libft/libft.h"

typedef struct pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd_argv;
	int		infile;
	int		outfile;
	char	*path;
	char	*cmd_path;
	int		tube[2];
}	t_pipex;
int		main(int argc, char **argv, char **envp);
void	ft_first_process(char **argv, char **envp, t_pipex pipex);
void	ft_second_process(char **argv, char **envp, t_pipex pipex);
void	ft_free_child(t_pipex *pipex);
void	ft_free_parent(t_pipex *pipex);
void	ft_msg_error(char *err);
int		ft_msg_child_error(char *err);
#endif
