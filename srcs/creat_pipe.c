#include "../include/pipex_bonus.h"
# include "../include/pipex.h"

pid_t	*create_pipe(void)
{
	pid_t ids[2];

	if (pipe(ids) < 0)
		pipex_error("pipe Not Create succuss");
	return (ids);
}