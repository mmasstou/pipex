/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:37:44 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/04 22:50:51 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**stock_path(char *envp)
{
	char	*str;
	char	**path;

	str = ft_strtrim(envp, "PATH=");
	path = ft_split(str, ':');
	free(str);
	return (path);
}

char	**get_path(char **envp)
{
	int		index;
	char	**path;

	index = 0;
	path = NULL;
	if (!envp)
		pipex_error("envarement Not Found !");
	while (envp[index])
	{
		if (ft_strnstr(envp[index], "PATH=/", ft_strlen("PATH=/")) != 0)
		{
			path = stock_path(envp[index]);
			break ;
		}
		index++;
	}
	if (!path)
		pipex_error("PATH Not Found !");
	return (path);
}
