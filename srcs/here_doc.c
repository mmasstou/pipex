#include "../include/pipex_bonus.h"

int	here_doc(char **argv, t_pipe	*ids)
{
	char	*buffer;

	if (pipe(ids->hd_pip) < 0)
		pipex_error("pipe Not Create succuss");
	while (1)
	{
		ft_putstr_fd("\x1b[34m here_doc > \x1b[0m",1);
		buffer = get_next_line(0);
		if (ft_strncmp(buffer, argv[2],ft_strlen(argv[2])) == 0)
		{
			// free(buffer);
			break;
		}
		ft_putstr_fd(buffer, ids->hd_pip[1]);
		free(buffer);
	}
	close(ids->hd_pip[1]);
	return (0);
}
