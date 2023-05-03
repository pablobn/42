/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbengoec <pbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:15:59 by pbengoec          #+#    #+#             */
/*   Updated: 2023/04/25 20:50:13 by pbengoec         ###   ########.fr       */
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
	char	**argv;
	int		infile;
	int		outfile;
	char	*path;
	int		pid1;
	int		pid2;
	char	*cmd_path;
	int		tube[2];
} t_pipex;

int	main(int argc, char **argv, char **envp);
#endif
