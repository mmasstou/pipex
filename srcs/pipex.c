/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:41:11 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/31 14:14:08 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*ids;
	t_cmds	**cmds;

	ids = (t_pipe *)malloc(sizeof(t_pipe));
	if (!ids)
		pipex_error("malloc error !");
	if (argc == 5)
	{
		open_infile(ids, argv[1]);
		open_outfile(ids, argv[argc - 1]);
		cmds = get_path_cmd(argc, argv, envp, 2);
		cmds_process(argc, cmds, envp, ids);
		free(ids);
		free_path_cmd(cmds);
	}
	else
		open_error("syntax error : ./pipex infile cmd1 cmd2 ... outfile");
}
