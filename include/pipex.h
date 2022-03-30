/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:22:59 by mmasstou          #+#    #+#             */
/*   Updated: 2022/03/30 12:30:39 by mmasstou         ###   ########.fr       */
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
# define PATH_OK 0
# define PATH_KO 1

// colors
# define C_SUCCESS "\033[38;5;42m"
# define C_FAILURE "\x1b[31m"
# define C_END "\x1b[0m"

typedef struct fd
{
	int	in;
	int	out;
}	t_fd;
typedef struct s_pipe
{
	int		fd[2];
	pid_t	pipe[2];
	int		forkid;
	pid_t	hd_pip[2];
}	t_pipe;

// open Function
int		open_fd(int *index, char *filename, int type);
void	open_outfile(t_pipe *ids, char *filename);
void	open_infile(t_pipe *ids, char *filename);

char	**get_path(char **envp);
void	child_process_in(t_pipe *ids, char **path, char **envp, char *argv);
void	child_process_out(t_pipe *ids, char **path, char **envp, char *argv);
char	**get_cmd_flag(char *str);
// pipex_utils
void	ft_pipe(t_pipe *ids);
void	ft_fork(t_pipe *ids);
void	dup_close(int newfd, int oldfd);

// Errors
int		open_error(char *msg);
void	pipex_error(char *msg);
// free
void	free_path(char **path);
#endif