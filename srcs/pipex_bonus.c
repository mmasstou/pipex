#include "../include/pipex_bonus.h"
#include "../include/pipex.h"

/**
 * ! fd[0] --> pipe
 * ! fd[1] --> fork
 * ! fd[2] --> in / out file 
 **/


int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	t_commends	**cmds;
	t_pipe	*ids;
	char	*buff;

	int		jndex;


	cmds = (t_commends	**)malloc(sizeof(t_commends	*));
	buff = (char *)malloc(sizeof(char) * 1000);
	ids = (t_pipe *)malloc(sizeof(t_pipe));
	ids->fd = (t_fd *)malloc(sizeof(t_fd));
	if (!ids || !ids->fd || !buff || !cmds)
		pipex_error("malloc error !");
	if (argc >= 5)
	{
		paths = get_path(envp);
		if (ft_strncmp(argv[1], "here_doc",8) == 0)
		{
			here_doc(argv, ids);
			cmds = get_path_cmd(argc, argv, paths, 3);
			ids->fd->out = open(argv[argc - 1],O_CREAT | O_WRONLY | O_TRUNC , 0777);
			if (ids->fd->out < 0)
				pipex_error("outfile not opened successful");
			// commends
			jndex = 0;
			while(cmds[jndex] != NULL)
			{
				pipe(ids->pipe);
				if (ids->pipe < 0)
					pipex_error("pipe error !");
				ids->forkid = fork();
				if (ids->forkid < 0)
					pipex_error("fork error !");
				if (ids->forkid == 0)
				{
					dup2(ids->hd_pip[0], 0);
					close(ids->hd_pip[0]);
					dup2(ids->pipe[1], 1);

					if (jndex == argc - 5)
					{
						dup2(ids->fd->out, 1);
						close(ids->fd->out);
					}
					execve(cmds[jndex]->path, cmds[jndex]->cmd, envp);
				}
				//close(ids->pipe[0]);
				close(ids->pipe[1]);
				ids->hd_pip[0] = ids->pipe[0];
				waitpid(ids->forkid, NULL, 0);
				jndex++;
			}
			// end cmds
			close(ids->hd_pip[0]);
			close(ids->hd_pip[1]);
		}
		else
		{
			ids->fd->in = open(argv[1],O_RDONLY, 0777);
			if (ids->fd->in < 0 )
				pipex_error("infile not opened successful");
			cmds = get_path_cmd(argc, argv, paths, 2);
			jndex = 0;
			while(cmds[jndex] != NULL)
			{
				pipe(ids->pipe);
				if (ids->pipe < 0)
					pipex_error("pipe error !");
				ids->forkid = fork();
				if (ids->forkid < 0)
					pipex_error("fork error !");
				if (ids->forkid == 0)
				{
					dup2(ids->fd->in, 0);
					close(ids->fd->in);
					dup2(ids->pipe[1], 1);

					if (jndex == argc - 4)
					{
						dup2(ids->fd->out, 1);
						close(ids->fd->out);
					}
					execve(cmds[jndex]->path, cmds[jndex]->cmd, envp);
				}
				//close(ids->pipe[0]);
				close(ids->pipe[1]);
				ids->fd->in = ids->pipe[0];
				waitpid(ids->forkid, NULL, 0);
				jndex++;
			}
			return (0);
		}
	}
	else
		return (ft_putendl_fd("Program\
e Run like this  ./pipex infile cmd1 cmd2 outfile", 2), 1);
}
