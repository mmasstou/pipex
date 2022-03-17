#include "../include/pipex.h"

/**
 * ! fd[0] --> pipe
 * ! fd[1] --> fork
 * ! fd[2] --> in / out file 
 **/
int main(int argc, char *argv[], char *envp[])
{
    char    **path;
	t_pipe     *ids;

    path = NULL;
    if (argc == 5)
    {
        path = get_cmds(envp);
        ids = create_env(argv[1],argv[4]);
        if ((ids->forkid = fork()) < 0)
            return (ft_putendl_fd("Fork failure", 2), 1);
        if (ids->forkid == 0)
            child_process_in(ids, path, envp, argv[2]);
        if ((ids->forkid = fork()) < 0)
            return (ft_putendl_fd("Fork failure", 2), 1);
         if (ids->forkid == 0)
            child_process_out(ids, path, envp, argv[3]);
        close(ids->pipe[0]);
        close(ids->pipe[1]);
        waitpid(ids->forkid, NULL, 0);
        free_path(path); 
    }
    else
        return (ft_putendl_fd("Programe Run like this  ./pipex infile cmd1 cmd2 outfile", 2), 1); 
    // while(1);
    return (0); 
}