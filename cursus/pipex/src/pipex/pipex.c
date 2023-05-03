/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:10:17 by pbengoec          #+#    #+#             */
/*   Updated: 2023/04/27 20:32:59 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_cmd(t_pipex pipex, char *str)
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
		i++;
	}
	return (NULL);
}

void	ft_first_process(char **argv, char **envp, t_pipex pipex)
{
	char	**argve;

	dup2(pipex.tube[1], pipex.infile);
	close(pipex.tube[0]);
	dup2(pipex.infile, 0);
	pipex.argv = NULL;
	argve = ft_split(argv[2], ' ');
	pipex.cmd_path = ft_get_cmd(pipex, ft_strjoin("/", argve[0]));
	printf("%s\n", pipex.cmd_path);
	printf("%s\n", argve[0]);
	printf("%s\n", argve[1]);
	printf("EXECVE %d\n", execve(pipex.cmd_path, argve, envp));
	return ;
}

void	ft_second_process(char **argv, char **envp, t_pipex pipex)
{
	argv = NULL;
	envp = NULL;
	pipex.tube[0] = 0;
	return ;
}

char	*ft_get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4) != 0)
		envp++;
	return (*envp+5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		return (1);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (pipex.outfile < 0)
		return (1);
	pipex.path = ft_get_path(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_first_process(argv, envp, pipex);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		// ft_second_process(argv, envp, pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	close(pipex.outfile);
	close(pipex.infile);
	return (0);
}
	//PATH=/Users/pbengoec/.brew/bin
	///usr/local/bin:
	// /usr/bin:
	// /bin:
	// /usr/sbin:
	// /sbin:
	// /usr/local/share/dotnet:
	// /usr/local/munki:
	// ~/.dotnet/tools:
	// /Library/Frameworks/Mono.framework/Versions/Current/Commands:
	// /Users/pbengoec/.brew/bin

	// argc = 0;
	// argv = NULL;
	// char * argve[] = {"ls", "-a",NULL};

	// printf("ACCESS %d\n", access("/bin", 0));
	// printf("EXECVE %d\n", execve("/bin/ls", argve, envp));
