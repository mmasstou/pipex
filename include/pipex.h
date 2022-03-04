#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

char    *get_commend(char **in_cmd, char **path);
char	**get_cmd_flag(char *str);

#endif