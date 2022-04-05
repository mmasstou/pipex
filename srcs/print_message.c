/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:25:37 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/05 14:07:19 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	commend_find_successfull(t_cmds *cmds, int status)
{
	char	*str;

	if (status == PATH_OK)
	{
		str = ft_strjoin("\x1b[36m[", cmds->path);
		str = re_join(str, "]\x1b[0m");
		ft_printf("\x1b[36m   +> \033[0m%-22s%-38s%s\n", \
			cmds->cmd[0], str, "\033[38;5;42m OK\033[0m");
		free(str);
	}
	if (status == PATH_KO)
		ft_printf("\x1b[36m   +> \033[0m%-22s%-38s%s\n", cmds->cmd[0], \
			"\x1b[31mCommend not Found !\x1b[0m", "\x1b[31m KO \x1b[0m");
}

void	emty_arg_v(char *argv)
{
	ft_printf("%s%-22s%-38s%s\n", C_F, argv, \
		"\x1b[31mEmty Argument Vector !\x1b[0m", "\x1b[31m KO \x1b[0m");
	exit(EXIT_FAILURE);
}
