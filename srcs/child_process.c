/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:37:43 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/17 16:54:51 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	execve_with_path(char *argv, char *envp[])
{
	int		index;
	char	*str;
	char	**commend;

	index = access(argv, X_OK);
	str = ft_strrchr(argv, '/');
	commend = ft_split(str, '/');
	if (index == 0)
		execve(argv, &commend[0], envp);
	return (index);
}

int	execve_with_cmd(char **path, char *argv, char *envp[])
{
	int		index[2];
	char	*str;
	char	**commend;

	commend = ft_split(argv, ' ');
	index[0] = -1;
	while (path[++index[0]])
	{
		str = ft_strjoin(path[index[0]], "/");
		str = ft_strjoin(str, commend[0]);
		index[1] = access(str, X_OK);
		if (index[1] == 0)
			execve(str, commend, envp);
	}
	return (index[1]);
}

void	child_process_in(t_pipe *ids, char **path, char **envp, char *argv)
{
	int	index[2];

	dup2(ids->fd->in, 0);
	dup2(ids->pipe[1], 1);
	close(ids->fd->in);
	close(ids->pipe[0]);
	close(ids->pipe[1]);
	if (argv[0] == '/')
		index[1] = execve_with_path(argv, envp);
	else
		execve_with_cmd(path, argv, envp);
	if (index[1] != 0)
	{
		ft_putstr_fd(argv, 2);
		ft_putendl_fd(" :cmd Not Found !", 2);
		exit (1);
	}
}

void	child_process_out(t_pipe *ids, char **path, char **envp, char *argv)
{
	int		index[2];

	dup2(ids->pipe[0], 0);
	dup2(ids->fd->out, 1);
	close(ids->fd->out);
	close(ids->pipe[0]);
	close(ids->pipe[1]);
	if (argv[0] == '/')
		index[1] = execve_with_path(argv, envp);
	else
		execve_with_cmd(path, argv, envp);
	if (index[1] != 0)
	{
		ft_putstr_fd(argv, 2);
		ft_putendl_fd(" :cmd Not Found !", 2);
		exit (1);
	}
}
