/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:39:32 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/29 15:52:53 by mmasstou         ###   ########.fr       */
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

void	open_outfile(t_pipe *ids, char *filename)
{
	ids->fd[1] = open(filename,O_CREAT | O_WRONLY | O_TRUNC , 0777);
	if (ids->fd[1] < 0)
		pipex_error("outfile not opened successful");
}

void	open_infile(t_pipe *ids, char *filename)
{
	ids->fd[0] = open(filename,O_RDONLY, 0777);
	if (ids->fd[0] < 0 )
		pipex_error("infile not opened successful");
}