/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:26:33 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/18 21:26:49 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipe	*create_env(char *infile, char *outfile)
{
	char	*str;
	t_pipe	*pepex;

	pepex = (t_pipe *)malloc(sizeof(t_pipe));
	if (!pepex)
		pipex_error("malloc error !");
	str = ft_strjoin("no such file or directory: ", infile);
	pepex->fd[0] = open(infile, O_RDONLY |  O_TRUNC);
	if (pepex->fd[0] < 0)
		open_error(str);
	free(str);
	str = ft_strjoin("no such file or directory: ", outfile);
	pepex->fd[1] = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pepex->fd[1] < 0)
		open_error(str);
	free(str);
	if (pipe(pepex->pipe) < 0)
		pipex_error("pipe Not Create succuss");
	return (pepex);
}
