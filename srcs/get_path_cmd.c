#include "../include/pipex_bonus.h"

char	**get_path_cmd(int argc, char **argv, char **path)
{
	char	**commends;
	char	**cmd;
	int		index;
	int		jndex;
	int		i;
	int		j;

	j = 0;
	index = 0;
	jndex = 3;
	commends = (char **)malloc(sizeof(char *) + 1);

	while (argv[jndex] && jndex < argc - 1)
	{
		cmd = ft_split(argv[jndex], ' ');
		index = 0;
		while(path[index])
		{
			commends[j] = ft_strjoin(path[index], "/");
			commends[j] = ft_strjoin(commends[j], cmd[0]);
			i = access(commends[j], X_OK);
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