/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:41:11 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/17 17:38:28 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * ! fd[0] --> pipe
 * ! fd[1] --> fork
 * ! fd[2] --> in / out file 
 **/
int	main(int argc, char *argv[], char *envp[])
{
	char	**path;
	t_pipe	*ids;

	if (argc == 5)
	{
		path = get_path(envp);
		ids = create_env(argv[1], argv[4]);
		ids->forkid = ft_fork();
		if (ids->forkid == 0)
			child_process_in(ids, path, envp, argv[2]);
		ids->forkid = ft_fork();
		if (ids->forkid == 0)
			child_process_out(ids, path, envp, argv[3]);
		close(ids->pipe[0]);
		close(ids->pipe[1]);
		waitpid(ids->forkid, NULL, 0);
		free_path(path);
		return (0);
	}
	else
		return (ft_putendl_fd("Program\
e Run like this  ./pipex infile cmd1 cmd2 outfile", 2), 1);
}
