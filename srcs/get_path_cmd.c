/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:09:00 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/30 18:40:38 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	commend_find_successfull(t_cmds *cmds, int status)
{
	if (status == PATH_OK)
		printf("%s[%s]%s\n", cmds->cmd[0],cmds->path, "\033[38;5;42m OK\033[0m");
	if (status == PATH_KO)
		printf("%s[%s]%s\t", cmds->cmd[0],cmds->path, "\x1b[31m KO \x1b[0m");
}

void	find_path(t_cmds **commends, char **paths, int *j, int *incmd)
{
	int	index;
	int	i;

	index = -1;
	while (paths[++index])
	{
		commends[*j]->path = ft_strjoin(paths[index], "/");
		commends[*j]->path = re_join(commends[*j]->path, commends[*j]->cmd[0]);
		i = access(commends[*j]->path, X_OK);
		if (i == 0)
		{
			commend_find_successfull(commends[*j], PATH_OK);
			(*incmd)++;
			break ;
		}
	}
	if (i != 0)
	{
		commend_find_successfull(commends[*j], PATH_KO);
		pipex_error("Commend not Found !");
	}
}

t_cmds	**get_path_cmd(int argc, char **argv, char *envp[], int incmd)
{
	t_cmds	**commends;
	int		jndex;
	char	**paths;
	int		j;

	paths = get_path(envp);
	j = 0;
	jndex = argc - (1 + incmd);
	commends = (t_cmds **)malloc(sizeof(t_cmds *) * (jndex + 1));
	if (!commends)
		pipex_error("malloc error !");
	while (j < jndex)
	{
		commends[j] = (t_cmds *)malloc(sizeof(t_cmds));
		if (!commends[j])
			pipex_error("malloc error !");
		commends[j]->cmd = ft_split(argv[incmd], ' ');
		find_path(commends, paths, &j, &incmd);
		j++;
	}
	commends[j] = NULL;
	return (commends);
}
