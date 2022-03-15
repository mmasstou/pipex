#include "../include/pipex.h"

void    get_cmds(char **path, char **envp)
{
    int     index;
    char    *str;

    index = 0;
    str = NULL;
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
}