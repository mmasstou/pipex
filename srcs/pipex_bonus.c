/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:53:26 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/30 19:05:37 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"
#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*ids;
	t_cmds	**cmds;

	ids = (t_pipe *)malloc(sizeof(t_pipe));
	if (!ids)
		pipex_error("malloc error !");
	if (argc >= 5)
	{
		if (ft_strcmp(argv[1], "here_doc") == 0)
			here_doc_process(argc, argv, envp, ids);
		else
		{
			open_infile(ids, argv[1]);
			open_outfile(ids, argv[argc - 1]);
			cmds = get_path_cmd(argc, argv, envp, 2);
			cmds_process(argc, cmds, envp, ids);
		}
	}
	else
		open_error("syntax error : ./pipex infile cmd1 cmd2 ... outfile");
}
