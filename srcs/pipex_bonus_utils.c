#include "../include/pipex_bonus.h"
#include "../include/pipex.h"

void	ft_pipe(t_pipe *ids)
{
	pipe(ids->pipe);
	if (ids->pipe < 0)
		pipex_error("pipe error !");
}

void	ft_fork(t_pipe *ids)
{
	ids->forkid = fork();
	if (ids->forkid < 0)
		pipex_error("fork error !");
}

void	dup_close(int newfd, int oldfd)
{
	dup2(newfd, oldfd);
	close(newfd);
}