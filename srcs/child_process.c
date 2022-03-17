#include "../include/pipex.h"

int execve_with_path(char *argv, char *envp[])
{
    // int     index[2];
    // char    *str;
    char **commend;

    commend = ft_split(argv, '/');
    printf("envp[0] : %s -----commend : %s\n",envp[0], commend[-2]);
    return (0);

}
int execve_with_cmd(char **path, char **cmd, char *envp[])
{
    int     index[2];
    char    *str;

    index[0] = -1;
    while (path[++index[0]])
    {
        str = ft_strjoin(path[index[0]], "/");
        str = ft_strjoin(str, cmd[0]);
        index[1] = access(str, X_OK);
        if (index[1] == 0)
            execve(str,cmd, envp);
    }
    return (1);
}


void    child_process_in(t_pipe *ids, char **path, char **envp, char *argv)
{
    char **cmd;
    char *str;
    int index[2];

    dup2(ids->fd->in, 0);
    dup2(ids->pipe[1], 1);
    close(ids->fd->in);
    close(ids->pipe[0]);
    close(ids->pipe[1]);

    if (argv[0] == '/')
    {
        index[1] = access(argv, X_OK);
        str = ft_strrchr(argv, '/');
        cmd = ft_split(str, '/');
        if (index[1] == 0)
            execve(argv,&cmd[0], envp);
    }
    else
    {
        cmd = ft_split(argv, ' ');
        index[0] = -1;
        while (path[++index[0]])
        {
            str = ft_strjoin(path[index[0]], "/");
            str = ft_strjoin(str, cmd[0]);
            index[1] = access(str, X_OK);
            if (index[1] == 0)
                execve(str,cmd, envp);
        }
    }
    if (index[1] != 0)
    {
        ft_putstr_fd(argv, 2);
        ft_putendl_fd(" :cmd Not Found !", 2);
        exit (1);
    }
    index[0] = -1;
    while (cmd[++index[0]])
        free(cmd[index[0]]);
    free(cmd);
    free(str);   
}


void    child_process_out(t_pipe *ids, char **path, char **envp, char *argv)
{
    char **cmd;
    char *str;
    int index[2];

    dup2(ids->pipe[0], 0);
    dup2(ids->fd->out, 1);
    close(ids->fd->out);
    close(ids->pipe[0]);
    close(ids->pipe[1]);
    if (argv[0] == '/')
    {
        index[1] = access(argv, X_OK);
        str = ft_strrchr(argv, '/');
        cmd = ft_split(str, '/');
        if (index[1] == 0)
            execve(argv,&cmd[0], envp);
    }
    else
    {
        cmd = ft_split(argv, ' ');
        index[0] = -1;
        while (path[++index[0]])
        {
            str = ft_strjoin(path[index[0]], "/");
            str = ft_strjoin(str, cmd[0]);
            index[1] = access(str, X_OK);
            if (index[1] == 0)
                execve(str,cmd, envp);
        }
    }
    if (index[1] != 0)
    {
        ft_putstr_fd(argv, 2);
        ft_putendl_fd(" :cmd Not Found !", 2);
        exit (1);
    }
    index[0] = -1;
    while (cmd[++index[0]])
        free(cmd[index[0]]);
    free(cmd);
    free(str);
}
