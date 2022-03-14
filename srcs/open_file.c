#include "../include/pipex.h"

int open_fd(int *index, char *filename, int type)
{
    char *str;
    str = NULL;
    *index = open(filename, type, 0777);
    if (*index < 0)
    {
        str = ft_strjoin("no such file or directory: ", filename);
        open_error(str);
    }
    return (SUCCESS) ;
}