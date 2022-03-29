#include "../include/pipex_bonus.h"

int	here_doc(char **argv, t_pipe	*ids)
{
	char	*buffer;

	if (pipe(ids->hd_pip) < 0)
		pipex_error("pipe Not Create succuss");
	while (1)
	{
		ft_putstr_fd("\x1b[34m here_doc > \x1b[0m",1);
		buffer = get_next_line(0);
		if (ft_strncmp(buffer, argv[2],ft_strlen(argv[2])) == 0)
		{
			// free(buffer);
			break;
		}
		ft_putstr_fd(buffer, ids->hd_pip[1]);
		free(buffer);
	}
	close(ids->hd_pip[1]);
	return (0);
}
void	here_doc_process(int argc, char *argv[], char *envp[], t_pipe *ids)
{
	t_commends	**cmds;
	int			jndex;

	here_doc(argv, ids);
	open_outfile(ids, argv[argc - 1]);
	// ids->fd[1] = open(argv[argc - 1],O_CREAT | O_WRONLY | O_TRUNC , 0777);
	// if (ids->fd[1] < 0)
	// 	pipex_error("outfile not opened successful");
	cmds = get_path_cmd(argc, argv, envp, 3);
	jndex = 0;
	while(cmds[jndex] != NULL)
	{
		ft_pipe(ids);
		ft_fork(ids);
		if (ids->forkid == 0)
		{
			dup_close(ids->hd_pip[0], 0);
			dup2(ids->pipe[1], 1);
			if (jndex == argc - 5)
				dup_close(ids->fd[1], 1);
			execve(cmds[jndex]->path, cmds[jndex]->cmd, envp);
		}
		close(ids->pipe[1]);
		ids->hd_pip[0] = ids->pipe[0];
		waitpid(ids->forkid, NULL, 0);
		jndex++;
	}
	close(ids->hd_pip[0]);
	close(ids->hd_pip[1]);
	free_path_cmd(cmds);
	free(ids);
}