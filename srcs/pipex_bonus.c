#include "../include/pipex_bonus.h"
#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	t_commends	**cmds;
	t_pipe	*ids;
	

	int		jndex;
	int		i;
	int		j;

	i = getpid();
	printf("Parent id %d\n", i);
	cmds = NULL;
	ids = (t_pipe *)malloc(sizeof(t_pipe));
	ids->fd = (t_fd *)malloc(sizeof(t_fd));
	if (!ids || !ids->fd)
		pipex_error("malloc error !");
	j = 0;
	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc",8) == 0)
		{
			here_doc(argv, ids);
			ids->fd->out = open(argv[argc - 1],O_CREAT | O_WRONLY | O_TRUNC , 0777);
			if (ids->fd->out < 0)
				pipex_error("outfile not opened successful");
			// commends
			paths = get_path(envp);
			cmds = get_path_cmd(argc, argv, paths, 3);
			jndex = 0;
			while(cmds[jndex] != NULL)
			{
				pipe(ids->pipe);
				if (ids->pipe < 0)
					pipex_error("pipe error !");
				ids->forkid = fork();
				if (ids->forkid < 0)
					pipex_error("fork error !");
				j = getpid();
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
				// free_ids(ids);
			}
			// end cmds
			close(ids->hd_pip[0]);
			close(ids->hd_pip[1]);
			free_path_cmd(cmds);
			// free_ids(ids);
			free_path(paths);
		}
		else
		{
			ids->fd->in = open(argv[1],O_RDONLY, 0777);
			if (ids->fd->in < 0 )
				pipex_error("infile not opened successful");
			paths = get_path(envp);
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
			// return (0);
			free_path_cmd(cmds);
			free_ids(ids);
			free_path(paths);
			exit(0);
		}
		// while(1);
	}
	else
		return (ft_putendl_fd("Programe Run like this  ./pipex infile cmd1 cmd2 outfile", 2), 1);
}
