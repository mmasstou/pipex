/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:39:32 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/31 19:24:47 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_fd(int *index, char *filename, int type)
{
	char	*str;

	str = NULL;
	*index = open(filename, type, 0777);
	if (*index < 0)
	{
		str = ft_strjoin("no such file or directory: ", filename);
		open_error(str);
	}
	return (SUCCESS);
}

void	open_outfile_heredoc(t_pipe *ids, char *filename)
{
	char	*str;

	ids->fd[1] = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (ids->fd[1] < 0)
	{
		str = ft_strjoin(filename,": No such file or directory");
		pipex_error_free(str);
	}
}

void	open_outfile(t_pipe *ids, char *filename)
{
	char	*str;

	ids->fd[1] = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (ids->fd[1] < 0)
	{
		str = ft_strjoin(filename,": No such file or directory");
		pipex_error_free(str);
	}
}

void	open_infile(t_pipe *ids, char *filename)
{
	char	*str;

	ids->fd[0] = open(filename, O_RDONLY, 0777);
	if (ids->fd[0] < 0)
	{
		str = ft_strjoin(filename,": No such file or directory");
		pipex_error_free(str);
	}
}
