/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:40:04 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/05 14:08:25 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../include/pipex.h"
# include "../get_next_line/get_next_line.h"

typedef struct commends
{
	char	*path;
	char	**cmd;
}	t_cmds;

int		cheack_abs_path(t_cmds **commends, char *path, int *j, int *incmd);
t_cmds	**get_path_cmd(int argc, char **argv, char **path, int incmd);
pid_t	*create_pipe(void);
void	free_path_cmd(t_cmds **cmds);
void	free_ids(t_pipe	*ids);
char	*re_join(char *str1, char *str2);
// messages
void	commend_find_successfull(t_cmds *cmds, int status);
void	emty_arg_v(char *argv);
// here_doc
int		here_doc(char **argv, t_pipe *ids);
void	here_doc_process(int argc, char *argv[], char *envp[], t_pipe *ids);
void	cmds_process(int argc, t_cmds **cmds, char *envp[], t_pipe *ids);

#endif