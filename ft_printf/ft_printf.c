

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			index;
	int			ret;
	t_printf	*tab;

	index = -1;
	tab = (t_printf *)malloc(sizeof(t_printf));
	if (!tab)
		return (0);
	tab->_rep = (t_rep *)malloc(sizeof(t_rep));
	if (!(tab->_rep))
		return (0);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	ret = 0;
	while (format[++index])
	{
		if (format[index] == '%')
			index = ft_eval_format(tab, format, index + 1);
		else
			ret += write(1, &format[index], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	return (free (tab), free (tab->_rep), ret);
}