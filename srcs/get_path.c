/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:37:44 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/30 13:19:32 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**get_path(char **envp)
{
	int		index;
	char	*str;
	char	**path;

	index = 0;
	str = NULL;
	path = NULL;
	while (envp[index])
	{
		if (ft_strnstr(envp[index], "PATH=/", ft_strlen("PATH=/")) != 0)
		{
			str = ft_strtrim(envp[index], "PATH=");
			path = ft_split(str, ':');
			free(str);
			break ;
		}
		index++;
	}
	if (path[0] == NULL)
	{
		ft_putendl_fd("Failure to Found PATH !", 2);
		index = 0;
		while (path[index])
		{
			free(path[index]);
			index++;
		}
		exit (1);
	}
	return (path);
}
