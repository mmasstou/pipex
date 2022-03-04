#include "../include/pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    int index;
    char    **mypath;
    char       **cmd;
    char    *str;
	int fd;

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
		fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
		if (fd == -1)
			return (ft_putendl_fd("file not found.",2), 1);
		//dup2(fd, 1);
		dup2(fd, 2);
        cmd = get_cmd_flag(argv[1]);
		str = get_commend(cmd, mypath);
		if (str == NULL)
			return (ft_putendl_fd("cmd not found.",2), 1);
        execve(str,cmd, envp);
    }
    else
        write(1," we run pipex like this ./pipex  cmd1 cmd2  ",45);
}