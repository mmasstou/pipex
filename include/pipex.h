#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include "../libft/libft.h"
#include <fcntl.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1
typedef struct s_fd
{
    int in; // 0
    int out; // 1

}   t_fd;

typedef struct s_pipeid
{
    int pipe; // 0

}   t_pipeid;

typedef struct s_pipe
{
    t_fd *fd;
    pid_t pipe[2];
    int forkid;

}   t_pipe;
// open Function
int     open_fd(int *index, char *filename, int type);
char    **get_cmds(char **envp);
void    child_process_in(t_pipe *ids, char **path, char **envp, char *argv);
void    child_process_out(t_pipe *ids, char **path, char **envp, char *argv);
t_pipe    *create_env(char *infile, char *outfile);
// int    get_cmd_path(char **path, char *env[]);
char    *get_commend(char **in_cmd, char **path);
char	**get_cmd_flag(char *str);
int     redirection_fd(int pipid[2], int fileid, int fd);
int     find_cmd_utils(char *argv, char **path, char *envp[]);
void    ft_fork(int id);
// Errors
int open_error(char *msg);
void    pipex_error(char *msg);

// free
void    free_path(char **path);
#endif