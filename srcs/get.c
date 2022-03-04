#include "../include/pipex.h"

char    *get_commend(char **in_cmd, char **path)
{
	char 	*cmd;
	int		index;
	int		access_result;

	index = 0;
	while (path[++index])
	{
		cmd = ft_strjoin(path[index], "/");
		cmd = ft_strjoin(cmd, in_cmd[0]);
		access_result = access(cmd, X_OK);
		if (access_result == 0)
			return (cmd);
	}
	return (NULL);
}

char	**get_cmd_flag(char *str)
{
	return(ft_split(str, ' '));
}