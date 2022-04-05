/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_abs_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:27:14 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/05 14:47:32 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	cheack_abs_path(t_cmds **commends, char *path, int *j, int *incmd)
{
	char	**str;
	int		i;
	int		m;

	m = -1;
	i = access(path, X_OK);
	if (i == 0)
	{
		commends[*j]->path = ft_strdup(path);
		str = ft_split(path, '/');
		while (str[++m])
			;
		m--;
		commends[*j]->cmd = ft_split(str[m], '/');
		commends[*j]->cmd[1] = NULL;
		commend_find_successfull(commends[*j], PATH_OK);
		(*j)++;
		(*incmd)++;
		return (0);
	}
	return (-1);
}
