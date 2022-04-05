/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:28:00 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/05 12:19:11 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

char	*re_join(char *str1, char *str2)
{
	char	*s;

	s = ft_strjoin(str1, str2);
	free(str1);
	return (s);
}

void	pipex_error(char *msg)
{
	char	*message;

	message = ft_strjoin("\x1b[31m", msg);
	message = re_join(message, "\x1b[0m");
	printf ("%s\n", message);
	free(message);
	exit(1);
}

void	pipex_error_free(char *msg)
{
	char	*message;

	message = ft_strjoin("\x1b[31m", msg);
	message = re_join(message, "\x1b[0m");
	printf ("%s\n", message);
	free(message);
	free(msg);
	exit(1);
}
