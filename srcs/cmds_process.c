/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:53:15 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/29 15:54:31 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	cmds_process(int argc, t_commends **cmds, char *envp[], t_pipe *ids)
{
	int	jndex;

	jndex = 0;
	while(cmds[jndex] != NULL)
	{
		ft_pipe(ids);
		ft_fork(ids);
		if (ids->forkid == 0)
		{
			dup_close(ids->fd[0], 0);
			dup2(ids->pipe[1], 1);
			if (jndex == argc - 4)
				dup_close(ids->fd[1], 1);
			execve(cmds[jndex]->path, cmds[jndex]->cmd, envp);
		}
		close(ids->pipe[1]);
		ids->fd[0] = ids->pipe[0];
		waitpid(ids->forkid, NULL, 0);
		jndex++;
	}
	free_path_cmd(cmds);
	free(ids);
}