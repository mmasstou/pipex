#include "ft_printf.h"

static int	flag_part1(t_printf *tab, const char *format, int index)
{
	if (format[index] == '+')
	{
		tab->plus = 1;
		tab->_rep->plus++;
		index++;
	}	
	if (format[index] == ' ')
	{
		tab->space = 1;
		tab->_rep->space++;
		index++;
	}
	if (format[index] == '#')
	{
		tab->shrap = 1;
		tab->_rep->shrap++;
		index++;
	}
	if (tab->shrap || tab->space || tab->plus || tab->width)
	{
		tab->is_flag = 1;
		tab->_rep->flags += (tab->space + tab->shrap + tab->plus);
	}
	return (index);
}

static int	get_per(const char *format, int index, t_printf *tab)
{
	tab->precision = 1;
	tab->_rep->precision *= 10 ;
	tab->_rep->precision += format[index] - 48;
	index++;
	return (index);
}

static int	flag_part2(t_printf *tab, const char *format, int index)
{
	if (format[index] == '-')
	{
		tab->dash = 1;
		tab->_rep->dash++;
		index++;
	}	
	if (format[index - 1] == '%' && format[index] == '0')
	{
		while (format[index] == '0')
		{
			tab->zero = 1;
			tab->_rep->zero++;
			index++;
		}
	}
	if (format[index] == '.')
	{
		tab->pnt = 1;
		tab->_rep->pnt++;
		index++;
		while (ft_isdigit(format[index]))
			index = get_per(format, index, tab);
	}
	return (index);
}

static void	ft_update_flags(t_printf *tab)
{
	tab->is_flag = 1;
	tab->_rep->flags = (tab->pnt + tab->dash + tab->zero);
	tab->_rep->flags += (tab->space + tab->shrap + tab->plus);
}

int	ft_eval_format(t_printf *tab, const char *format, int index)
{
	int		strat;

	strat = (index) + 1;
	while (!is_specifier(format[index]))
	{
		if (format[index] > '0' && format[index] <= '9')
		{
			while (ft_isdigit(format[index]))
			{
				tab->width = 1;
				tab->_rep->width = tab->_rep->width * 10 + format[index] - 48;
				index++;
			}
		}
		index = flag_part2(tab, format, index);
		index = flag_part1(tab, format, index);
	}
	if (tab->pnt || tab->dash || tab->zero
		|| tab->shrap || tab->space || tab->plus)
		ft_update_flags(tab);
	update_index(tab, index);
	flags_check(tab, format, index);
	ft_specifier(tab, format, index);
	return (index);
}
