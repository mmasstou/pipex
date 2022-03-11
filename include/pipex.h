#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct pipeid
{
    int in; // 0
    int out; // 1

}   t_pipeid;

int    get_cmd_path(char **path, char *env[]);
char    *get_commend(char **in_cmd, char **path);
char	**get_cmd_flag(char *str);
int     redirection_fd(int pipid[2], int fileid, int fd);
int     find_cmd_utils(char *argv, char **path, char *envp[]);
void    ft_fork(int id);

#endif