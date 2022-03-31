/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:40:04 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/31 14:32:39 by mmasstou         ###   ########.fr       */
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

t_cmds	**get_path_cmd(int argc, char **argv, char **path, int incmd);
pid_t	*create_pipe(void);
void	free_path_cmd(t_cmds **cmds);
void	free_ids(t_pipe	*ids);
char	*re_join(char *str1, char *str2);

// here_doc
int		here_doc(char **argv, t_pipe *ids);
void	here_doc_process(int argc, char *argv[], char *envp[], t_pipe *ids);
void	cmds_process(int argc, t_cmds **cmds, char *envp[], t_pipe *ids);

#endif