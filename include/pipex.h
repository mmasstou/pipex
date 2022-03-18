/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:22:59 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/18 21:21:54 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct fd
{
	int	in;
	int	out;
}	t_fd;
typedef struct s_pipe
{
	t_fd	*fd;
	pid_t	pipe[2];
	int		forkid;
	pid_t	hd_pip[2];
}	t_pipe;

// open Function
int		open_fd(int *index, char *filename, int type);
char	**get_path(char **envp);
void	child_process_in(t_pipe *ids, char **path, char **envp, char *argv);
void	child_process_out(t_pipe *ids, char **path, char **envp, char *argv);
t_pipe	*create_env(char *infile, char *outfile);
char	**get_cmd_flag(char *str);
int		ft_fork(void);
// Errors
int		open_error(char *msg);
void	pipex_error(char *msg);
// free
void	free_path(char **path);
#endif