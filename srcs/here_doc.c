#include "../include/pipex_bonus.h"

int	here_doc(char **argv, t_pipe	*ids)
{
	char	*buffer;
	char	*str;
	char	*hd_file;

	
	
	hd_file = ft_strjoin(".",argv[1]);
	str = ft_strjoin("no such file or directory: ", argv[1]);
	ids->fd->in = open(hd_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (ids->fd->in < 0)
		open_error(str);
	if (pipe(ids->hd_pip) < 0)
		pipex_error("pipe Not Create succuss");
	str = ft_strdup("");
	while (1)
	{
		ft_putstr_fd("\x1b[34m here_doc > \x1b[0m",1);
		buffer = get_next_line(0);
		// ft_putstr_fd(str, 1);	
		if (ft_strncmp(buffer, argv[2],ft_strlen(argv[2])) == 0)
			break;
		ft_putstr_fd(buffer, ids->hd_pip[1]);
	}
	close(ids->hd_pip[1]);
	return (0);
}
