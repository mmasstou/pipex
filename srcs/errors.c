#include "../include/pipex.h"

int open_error(char *msg)
{
    ft_putendl_fd(msg, 2);
    exit(1);
}

void    pipex_error(char *msg)
{
    ft_putendl_fd(msg, 2);
    exit(1);
}