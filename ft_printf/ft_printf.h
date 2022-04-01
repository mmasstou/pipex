#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_rep
{
	int	plus;
	int	perc;
	int	space;
	int	shrap;
	int	zero;
	int	dash;
	int	pnt;
	int	flags;
	int	width;
	int	precision;
}	t_rep;

typedef struct s_printf
{
	va_list	args;
	t_rep	*_rep;
	char	specifier;
	int		tl;
	int		plus;
	int		perc;
	int		space;
	int		shrap;
	int		zero;
	int		dash;
	int		pnt;
	int		is_flag;
	int		width;
	int		precision;
}	t_printf;

t_printf	*ft_initialise_tab(t_printf *tab);

# endif