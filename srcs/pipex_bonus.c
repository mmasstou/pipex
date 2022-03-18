#include "../include/pipex_bonus.h"

/**
 * ! fd[0] --> pipe
 * ! fd[1] --> fork
 * ! fd[2] --> in / out file 
 **/


int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	t_pipe	*ids;
	char	*buff;
	int		index;

	buff = (char *)malloc(sizeof(char) + 1);
	ids = (t_pipe *)malloc(sizeof(t_pipe));
	ids->fd = (t_fd *)malloc(sizeof(t_fd));
	if (!ids || !ids->fd || !buff)
		pipex_error("malloc error !");
	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc",8) == 0)
		{
			here_doc(argv, ids);
			paths = get_path(envp);
			paths = get_path_cmd(argc, argv, paths);
			index = read(ids->hd_pip[0],buff, 1);
			while (index > 0)
			{
				write(1,buff,1);
				index = read(ids->hd_pip[0],buff, 1);
			}
		}
		else
		{

		}
	}
	else
		return (ft_putendl_fd("Program\
e Run like this  ./pipex infile cmd1 cmd2 outfile", 2), 1);
}
