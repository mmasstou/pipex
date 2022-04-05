/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:09:00 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/05 14:04:39 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static t_cmds	*allocate_cmds(t_cmds	*commends)
{
	commends = (t_cmds *)malloc(sizeof(t_cmds));
	if (!commends)
		pipex_error("malloc error !");
	return (commends);
}

static t_cmds	**creat_env_cmds(int *j, int *jndex, int incmd, int argc)
{
	t_cmds	**commends;

	*j = 0;
	*jndex = argc - (1 + incmd);
	commends = (t_cmds **)malloc(sizeof(t_cmds *) * (*jndex + 1));
	if (!commends)
		pipex_error("malloc error !");
	return (commends);
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
		else
			free(commends[*j]->path);
	}
	if (i != 0)
	{
		commend_find_successfull(commends[*j], PATH_KO);
		exit(EXIT_FAILURE);
	}
}

t_cmds	**get_path_cmd(int argc, char **argv, char *envp[], int incmd)
{
	t_cmds	**commends;
	int		jndex;
	char	**paths;
	int		j;
	char	*str;

	paths = get_path(envp);
	commends = creat_env_cmds(&j, &jndex, incmd, argc);
	while (j < jndex)
	{
		commends[j] = allocate_cmds(commends[j]);
		str = ft_strtrim(argv[incmd], " ");
		if (str[0] == '\0')
			emty_arg_v(argv[incmd]);
		if (cheack_abs_path(commends, argv[incmd], &j, &incmd) == 0)
			continue ;
		commends[j]->cmd = ft_split(argv[incmd], ' ');
		find_path(commends, paths, &j, &incmd);
		free(str);
		j++;
	}
	free_path(paths);
	commends[j] = NULL;
	return (commends);
}
