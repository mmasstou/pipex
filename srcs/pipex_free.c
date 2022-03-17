#include "../include/pipex.h"

void    free_path(char **path)
{
    int index;

    index = -1;
    while (path[++index])
        free(path[index]);
    free(path);
}