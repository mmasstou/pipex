#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char *argv[], char *envp[])
{
    // int *fd;
    int index;
    char    **mypath;
    char       **cmd;
    char       *cmd_flag;
    char    *str;
    int i;

    // fd = 0;
    mypath = NULL;
    if (argc == 3)
    {
        index = 0;
        while (envp[index])
        {
            if (ft_strnstr(envp[index],"PATH=/", ft_strlen(envp[index])) != 0)
                mypath = ft_split(ft_strtrim(envp[index],"PATH="),':');
            index++;
        }
        index = -1;
        cmd_flag = argv[1];
        cmd = ft_split(cmd_flag,' ');
        while (mypath[++index])
        {
            str = ft_strjoin(mypath[index],"/");
            str = ft_strjoin(str,cmd[0]);
            i = access(str,X_OK);
            if (i == 0)
                execve(str,cmd, envp);
        }

    }
    else
        write(1," we run pipex like this ./pipex  cmd1 cmd2  ",45);
}