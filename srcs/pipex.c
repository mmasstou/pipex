/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:41:11 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/25 21:29:59 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipex_bonus.h"

/**
 * ! fd[0] --> pipe
 * ! fd[1] --> fork
 * ! fd[2] --> in / out file 
 **/
int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	t_commends	**cmds;
	t_pipe	*ids;
	char	*buff;

	int		jndex;
	int		j;


	cmds = (t_commends	**)malloc(sizeof(t_commends	*));
	buff = (char *)malloc(sizeof(char) * 8);
	ids = (t_pipe *)malloc(sizeof(t_pipe));
	ids->fd = (t_fd *)malloc(sizeof(t_fd));
	if (!ids || !ids->fd || !buff || !cmds)
		pipex_error("malloc error !");
	if (argc == 5)
	{
		paths = get_path(envp);
		ids->fd->in = open(argv[1],O_RDONLY, 0777);
		ids->fd->out = open(argv[argc - 1],O_CREAT | O_WRONLY | O_TRUNC , 0777);
		if (ids->fd->in < 0 || ids->fd->out < 0)
			pipex_error("file not opened successful");
		
		jndex = 0;
		cmds = get_path_cmd(argc, argv, paths, 2);
		j = 0;
		while(cmds[jndex] != NULL)
		{
			pipe(ids->pipe);
			if (ids->pipe < 0)
				pipex_error("pipe error !");
			ids->forkid = fork();
			if (ids->forkid < 0)
				pipex_error("fork error !");
			if (ids->forkid == 0)
			{
				dup2(ids->fd->in, 0);
				close(ids->fd->in);
				dup2(ids->pipe[1], 1);

				if (jndex == argc - 4)
				{
					dup2(ids->fd->out, 1);
					close(ids->fd->out);
				}
				execve(cmds[jndex]->path, cmds[jndex]->cmd, envp);
			}
			//close(ids->pipe[0]);
			close(ids->pipe[1]);
			ids->fd->in = ids->pipe[0];
			waitpid(ids->forkid, NULL, 0);
			jndex++;
		}
		free_path_cmd(cmds);
		while(1);
		return (0);
	}
	else
		pipex_error("Programe Run like this  ./pipex infile cmd1 cmd2 outfile");
}
