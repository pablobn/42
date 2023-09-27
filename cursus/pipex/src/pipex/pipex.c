/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:10:17 by pbengoec          #+#    #+#             */
/*   Updated: 2023/05/26 19:16:11 by pbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_get_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4) != 0)
	{
		envp++;
		if (*envp == NULL)
			ft_msg_error("No se encuentra la ruta PATH\n");
	}
	if (*envp == NULL)
		ft_msg_error("No se encuentra la ruta PATH\n");
	return (*envp + 5);
}

static void	ft_close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_msg_error("Error con los argumentos.\n");
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_msg_error("No existe el archivo que has introducido.\n");
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0000644);
	if (pipex.outfile < 0)
		ft_msg_error("Error creando el archivo de salida\n");
	pipex.path = ft_get_path(envp);
	pipe(pipex.tube);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_first_process(argv, envp, pipex);
	pipex.pid2 = fork();
	waitpid(pipex.pid1, NULL, 0);
	if (pipex.pid2 == 0)
		ft_second_process(argv, envp, pipex);
	ft_close_pipes(&pipex);
	waitpid(pipex.pid2, NULL, 0);
	ft_free_parent(&pipex);
	return (0);
}
