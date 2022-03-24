#include "../include/pipex_bonus.h"

t_commends	**get_path_cmd(int argc, char **argv, char **path, int incmd)
{
	t_commends	**commends;
	int		index;
	int		jndex;
	// char	*message;
	int		i;
	int		j;

	j = 0;
	index = 0;
	jndex = incmd;
	commends = (t_commends	**)malloc(sizeof(t_commends	*) * (argc - (1 + incmd) + 1));
	while (j < argc - (1 + incmd))
		commends[j++] = (t_commends *)malloc(sizeof(t_commends));
	j = 0;
	while (argv[jndex] && jndex < argc - 1)
	{
		// message = ft_strjoin(argv[jndex], " : Commend not Found !");
		commends[j]->cmd = ft_split(argv[jndex], ' ');
		index = 0;
		while(path[index])
		{
			commends[j]->path = ft_strjoin(path[index], "/");
			commends[j]->path = ft_strjoin(commends[j]->path, commends[j]->cmd[0]);
			i = access(commends[j]->path, X_OK);
			if (i == 0)
			{
				j++;
				jndex++;
				break;
			}
			index++;
		}
		if (i != 0)
			pipex_error("Commend not Found !");
	}
	commends[j] = NULL;
	return (commends);
}