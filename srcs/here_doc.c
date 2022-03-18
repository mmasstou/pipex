#include "../include/pipex_bonus.h"

int	here_doc(char **argv, t_pipe	*ids)
{
	char	*buffer;
	char	*str;
	char	*hd_file;

	
	if (ft_strncmp(argv[1], "here_doc",8) == 0)
	{
		hd_file = ft_strjoin(".",argv[1]);
		str = ft_strjoin("no such file or directory: ", argv[1]);
		ids->fd->in = open(hd_file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (ids->fd->in < 0)
			open_error(str);
		while (1)
		{
			str = ft_strdup("");
			ft_putstr_fd("here_doc > ",1);
			buffer = get_next_line(0);
			str = ft_strjoin(str, buffer);
			if (ft_strncmp(buffer, argv[2],ft_strlen(argv[2])) == 0)
				return (ids->fd->in);
			if (pipe(ids->hd_pip) < 0)
				pipex_error("pipe Not Create succuss");
			write(ids->hd_pip[1], str, ft_strlen(str));
		}
	}
	return (-1);
}
