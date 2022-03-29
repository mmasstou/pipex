#include "../include/pipex_bonus.h"

t_commends	**get_path_cmd(int argc, char **argv, char *envp[], int incmd)
{
	t_commends	**commends;
	int		index;
	int		jndex;
	char	**paths;
	int		i;
	int		j;

	paths = get_path(envp);
	j = 0;
	index = 0;
	jndex = incmd;
	commends = (t_commends	**)malloc(sizeof(t_commends	*) * (argc - (1 + incmd) + 1));
	while (j < argc - (1 + incmd))
	{
		commends[j] = (t_commends *)malloc(sizeof(t_commends));
		if (!commends[j])
		{
			while (commends[j])
			{
				free(commends[j]);
				j--;
			}
		}
		j++;
	}
	j = 0;
	while (argv[jndex] && jndex < argc - 1)
	{
		// message = ft_strjoin(argv[jndex], " : Commend not Found !");
		commends[j]->cmd = ft_split(argv[jndex], ' ');
		index = 0;
		while(paths[index])
		{
			commends[j]->path = ft_strjoin(paths[index], "/");
			commends[j]->path = re_join(commends[j]->path, commends[j]->cmd[0]);
			i = access(commends[j]->path, X_OK);
			if (i == 0)
			{
				j++;
				jndex++;
				break;
			}
			else
			{
				free(commends[j]->path);
			}
			index++;
		}
		if (i != 0)
		{
			free_path_cmd(commends);
			pipex_error("Commend not Found !");
		}
	}
	commends[j] = NULL;
	return (commends);
}