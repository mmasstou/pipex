/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:36:10 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/17 16:36:59 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_commend(char **in_cmd, char **path)
{
	char	*cmd;
	int		index;
	int		access_result;

	index = -1;
	while (path[++index])
	{
		cmd = ft_strjoin(path[index], "/");
		cmd = ft_strjoin(cmd, in_cmd[0]);
		access_result = access(cmd, X_OK);
		if (access_result == 0)
			return (ft_strdup(cmd));
	}
	return (NULL);
}

char	**get_cmd_flag(char *str)
{
	return (ft_split(str, ' '));
}