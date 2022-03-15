#include "../include/pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    int     index;
    char    **path;
    char    **cmd;
    char    *str;
	int     fd[2];
	int     pid[2];
    int     pipid[2];
    int     access_result;

    path = NULL;
    if (argc == 5)
    {
        index = 0;
        while (envp[index])
        {
            if (ft_strnstr(envp[index],"PATH=/", ft_strlen("PATH=/")) != 0)
            {
                str = ft_strtrim(envp[index],"PATH=");
                path = ft_split(str,':');
                free(str);
                break;
            }
            index++;
        }
        // get_cmds(path, envp);
        open_fd(&fd[0], argv[1], O_RDONLY );
        open_fd(&fd[1], argv[4], O_CREAT | O_WRONLY | O_TRUNC);

        if (pipe(pipid) > 0)
            return (ft_putendl_fd(" pipe Not Create succuss", 2), 1);
        
        if ((pid[0] = fork()) < 0)
            return (ft_putendl_fd("Fork failure", 2), 1);
        str = NULL;
        if (pid[0] == 0)
        {
            dup2(fd[0], 0);
            dup2(pipid[1], 1);
            close(fd[0]);
            close(pipid[0]);
            close(pipid[1]);
            cmd = ft_split(argv[2], ' ');
            index = -1;
            while (path[++index])
            {
                str = ft_strjoin(path[index], "/");
                str = ft_strjoin(str, cmd[0]);
                access_result = access(str, X_OK);
                if (access_result == 0)
                    execve(str,cmd, envp);
            }
            if (access_result != 0)
            {
                ft_putstr_fd(argv[2], 2);
                return (ft_putendl_fd(" :cmd Not Found !", 2), 1);
            }

            index = -1;
            while (cmd[++index])
                free(cmd[index]);
            free(cmd);
            free(str);
        }
        if ((pid[1] = fork()) < 0)
            return (ft_putendl_fd("Fork failure", 2), 1);
         if (pid[1] == 0)
        {
            dup2(pipid[0], 0);
            dup2(fd[1], 1);
            close(fd[1]);
            close(pipid[0]);
            close(pipid[1]);
            cmd = ft_split(argv[3], ' ');
            index = -1;
            while (path[++index])
            {
                str = ft_strjoin(path[index], "/");
                str = ft_strjoin(str, cmd[0]);
                access_result = access(str, X_OK);
                if (access_result == 0)
                    execve(str,cmd, envp);
            }
            if (access_result != 0)
            {
                ft_putstr_fd(argv[3], 2);
                return (ft_putendl_fd(" :cmd Not Found !", 2), 1);
            }
            index = -1;
            while (cmd[++index])
                free(cmd[index]);
            free(cmd);
            free(str);
        }

        close(pipid[0]);
        close(pipid[1]);
        waitpid(pid[0], NULL, 0);
    }
    else
        return (ft_putendl_fd("Programe Run like this  ./pipex infile cmd1 cmd2 outfile", 2), 1); 
    index = -1;
    // while (path[++index])
    //     free(path[index]);
    free(path);
    // while(1);
    return (0); 
}