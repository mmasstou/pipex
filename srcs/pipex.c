#include "../include/pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    int     index;
    char    **mypath;
    char    **cmd;
    char    *str;
	int     fd[2];

    mypath = NULL;
    if (argc == 4)
    {
        index = 0;
        while (envp[index])
        {
            if (ft_strnstr(envp[index],"PATH=/", ft_strlen("PATH=/")) != 0)
            {
                mypath = ft_split(ft_strtrim(envp[index],"PATH="),':');
                //break;
            }
            index++;
        }
        fd[0] = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC , 0777);
        if (fd[0] == -1)
            return (ft_putendl_fd("file not found.",2), 1);
		dup2(fd[0], STDOUT_FILENO);
        cmd = ft_split(argv[1], ' ');
        str = get_commend(cmd, mypath);
        if (str == NULL)
            return (ft_putendl_fd("cmd not found.",2), 1);
        execve(str,cmd, envp);
    }
    else
        write(1," we run pipex like this ./pipex  cmd1 cmd2  ",45);
}