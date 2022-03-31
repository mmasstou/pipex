/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:14:32 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/31 14:06:47 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipex_bonus.h"

void	free_path(char **path)
{
	int	index;

	index = -1;
	while (path[++index])
		free(path[index]);
	free(path);
}

void	free_path_cmd(t_cmds **cmds)
{
	int		jndex;

	jndex = 0;
	while (cmds[jndex] != NULL)
	{
		free(cmds[jndex]->path);
		free(cmds[jndex]->cmd[0]);
		if (cmds[jndex]->cmd[1] != NULL)
		{
			free(cmds[jndex]->cmd[1]);
			if (cmds[jndex]->cmd[2] != NULL)
				free(cmds[jndex]->cmd[2]);	
		}
		free(cmds[jndex]->cmd);
		free(cmds[jndex]);
		jndex++;
	}
	free(cmds);
}

void	free_ids(t_pipe	*ids)
{
	free(ids);
}
