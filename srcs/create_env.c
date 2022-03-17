#include "../include/pipex.h"

t_pipe    *create_env(char *infile, char *outfile)
{
    char *str;
    t_pipe *pepex;

    pepex = (t_pipe *)malloc(sizeof(t_pipe));
    pepex->fd = (t_fd *)malloc(sizeof(t_fd));
    if (!pepex || !pepex->fd)
        ft_error("malloc error !");
    str = ft_strjoin("no such file or directory: ", infile);
    pepex->fd->in = open(infile, O_RDONLY);
    if (pepex->fd->in < 0)
        open_error(str);
    free(str);
    str = ft_strjoin("no such file or directory: ", outfile);
    pepex->fd->out = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (pepex->fd->out < 0)
        open_error(str);
    free(str);
    if (pipe(pepex->pipe) > 0)
        ft_error("pipe Not Create succuss");
    return (pepex);
}