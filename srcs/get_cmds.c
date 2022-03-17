#include "../include/pipex.h"

char    **get_cmds(char **envp)
{
    int     index;
    char    *str;
    char **path;

    index = 0;
    str = NULL;
    path = NULL;
    while (envp[index])
    {
        if (ft_strnstr(envp[index],"PATH=/", ft_strlen("PATH=/")) != 0)
        {
            str = ft_strtrim(envp[index],"PATH=");
            path = ft_split(str,':');
            free(str);
            break;
        }
        index++;
    }
    if (path[0] == NULL)
    {
        ft_putendl_fd("FAILURE Failure to Found PATH !", 2);
        exit (1);
    }
    return (path);
}