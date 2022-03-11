#include "../include/pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    // int     index;
    char    **path;
    //char    **cmd;
    //char    *str;
	int     fd[2];
	int     pid[2];
    int     pipid[2];

    path = NULL;
    if (argc == 5)
    {
        if ( get_cmd_path(path, envp) == 1)
            return (ft_putendl_fd("samting wrong in envairement", 2), 1);
        fd[0] = open(argv[1], O_RDONLY, 0777);
        if (fd[0] < 0)
            return (ft_putendl_fd("infile Not opened succuss", 2), 1);
        fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fd[1] < 0)
                return (ft_putendl_fd(" outfile Not opened succuss", 2), 1);
        if (pipe(pipid) > 0)
            return (ft_putendl_fd(" pipe Not Create succuss", 2), 1);
        pid[0] = fork();
        if (pid[0] < 0)
            return (ft_putendl_fd("Fork failure", 2), 1);
        //ft_fork(pid[0]);
        if (pid[0] == 0)
        {
            printf("child 1 with Id:%d", pid[0]);
            if (redirection_fd(pipid, fd[0], 1) == 1)
                return (1);
            if (find_cmd_utils(argv[2], path, envp) == 1)
                return (ft_putendl_fd("cmd1 not found.",2), 1);
        }
        pid[1] = fork();
        if (pid[1] < 0)
            return (ft_putendl_fd("Fork failure", 2), 1);
        //ft_fork(pid[1]);
        if (pid[1] == 0)
        {
            printf("child 2 with Id:%d", pid[1]);
            if (redirection_fd(pipid, fd[1], 0) == 1)
                return (1);
            if (find_cmd_utils(argv[3], path, envp) == 1)
                return (ft_putendl_fd("cmd2 not found.",2), 1);
        }
        close(pipid[1]);
        close(pipid[0]);
        waitpid(pipid[0], NULL, 0);
        waitpid(pipid[1], NULL, 0);
        //return (ft_putendl_fd("Programe Run Succussfull", 1), 0);
    }
    else
        return (ft_putendl_fd("Programe Run like this  ./pipex infile cmd1 cmd2 outfile", 2), 1); 
    return (0); 
}