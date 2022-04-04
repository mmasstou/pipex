#include "ft_printf.h"
# include "libft.h"

void	get_value(int *is, int *value, const char *format, int *index)
{
	*is = 1;
	*value = *value * 10 + format[*index] - 48;
	(*index)++;
}

int is_specifier(int character)
{
    char    *specifiers;

    specifiers = "sS";
    return (ft_is_in(character, specifiers));
}

t_printf	*init_tab(t_printf *tab)
{
	tab->index = -1;
	tab->isdash = 0;
	tab->ispoint = 0;
	tab->isprecision = 0;
	tab->iswidth = 0;
	tab->precision = 0;
	tab->tl = 0;
	tab->width = 0;
	return (tab);
}

t_printf	*update_tab(t_printf *tab)
{
	tab->isdash = 0;
	tab->ispoint = 0;
	tab->isprecision = 0;
	tab->iswidth = 0;
	tab->precision = 0;
	tab->width = 0;
	return (tab);
}