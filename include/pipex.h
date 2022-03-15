#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include "../libft/libft.h"
#include <fcntl.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1
typedef struct pipeid
{
    int in; // 0
    int out; // 1

}   t_pipeid;

// open Function
int open_fd(int *index, char *filename, int type);
void    get_cmds(char *path[], char *envp[]);

int    get_cmd_path(char **path, char *env[]);
char    *get_commend(char **in_cmd, char **path);
char	**get_cmd_flag(char *str);
int     redirection_fd(int pipid[2], int fileid, int fd);
int     find_cmd_utils(char *argv, char **path, char *envp[]);
void    ft_fork(int id);
// Errors
int open_error(char *msg);

#endif