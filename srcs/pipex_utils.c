#include "../include/pipex.h"


int     redirection_fd(int pipid[2], int fileid, int fd)
{
    if (fd == 1)
    {
        dup2(pipid[1], STDOUT_FILENO);
        dup2(fileid, STDIN_FILENO);
    }
    else if (fd == 0)
    {
        dup2(pipid[0], STDIN_FILENO);
        dup2(fileid, STDOUT_FILENO);
    }
    else
        return (1);
    close(pipid[1]);
    close(pipid[0]);
    close(fileid);
    return (0);
}

int     find_cmd_utils(char *argv, char **path, char *envp[])
{
    char    **cmd;
    char    *str;

    cmd = ft_split(argv, ' ');
    str = get_commend(cmd, path);
    if (str == NULL)
        return (1);
    printf("cmd|%s %s  str|%s\n",cmd[0], cmd[1], str);
    execve(str,cmd, envp);
    return (0);
}

void    ft_fork(int id)
{
    id = fork();
    if (id < 0)
    {
        ft_putendl_fd("Fork failure", 2);
        exit(EXIT_FAILURE);
    }
}