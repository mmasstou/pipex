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

	int		index;
	int		jndex;


	cmds = (t_commends	**)malloc(sizeof(t_commends	*));
	buff = (char *)malloc(sizeof(char) * 8);
	ids = (t_pipe *)malloc(sizeof(t_pipe));
	ids->fd = (t_fd *)malloc(sizeof(t_fd));
	if (!ids || !ids->fd || !buff || !cmds)
		pipex_error("malloc error !");
	if (argc >= 5)
	{
		paths = get_path(envp);
		ids->fd->in = open(argv[1],O_RDONLY, 0777);
		ids->fd->out = open(argv[argc - 1],O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (ids->fd->in < 0 || ids->fd->out < 0)
			pipex_error("file not opened successful");
		if (ft_strncmp(argv[1], "here_doc",8) == 0)
		{
			here_doc(argv, ids);
			cmds = get_path_cmd(argc, argv, paths, 3);
			index = read(ids->hd_pip[0],buff, 8);
			while (index > 0)
			{
				ft_putstr_fd(buff, 1);
				index = read(ids->hd_pip[0],buff, 8);
			}
			close(ids->hd_pip[0]);
		}
		else
		{
			jndex = -1;
			cmds = get_path_cmd(argc, argv, paths, 2);
			// dup2(ids->fd->in, 0);
			while(cmds[++jndex])
			{
				if (pipe(ids->pipe) < 0)
					pipex_error("pipe Not Create succuss");
				ids->forkid = fork();
				if (ids->forkid < 0)
					pipex_error("Fork Not Work succuss");
				// printf("cmds[%d]->path%s\n", jndex, cmds[jndex]->path);
				// printf("cmds[%d]->cmd[0]%s\n", jndex, cmds[jndex]->cmd[0]);
				// printf("cmds[%d]->cmd[1]%s\n", jndex, cmds[jndex]->cmd[1]);
				if (ids->forkid == 0)
				{
					dup2(ids->pipe[1], 1);
					dup2(ids->pipe[0], 0);
					close(ids->pipe[0]);
					close(ids->pipe[1]);
					printf("1 - cmds[%d]->path%s\n", jndex, cmds[jndex]->path);
					printf("1 - cmds[%d]->cmd[0]%s\n", jndex, cmds[jndex]->cmd[0]);
					printf("1 - cmds[%d]->cmd[1]%s\n", jndex, cmds[jndex]->cmd[1]);
					// execve(cmds[jndex]->path, cmds[jndex]->cmd, envp);
					exit(0);
				}
				waitpid(ids->forkid, NULL, 0);
			}
			dup2(ids->fd->out, ids->pipe[1]);
			close(ids->pipe[0]);
			close(ids->pipe[1]);
			waitpid(ids->forkid, NULL, 0);
		}
	}
	else
		return (ft_putendl_fd("Program\
e Run like this  ./pipex infile cmd1 cmd2 outfile", 2), 1);
}
