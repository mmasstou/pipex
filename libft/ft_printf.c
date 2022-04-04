/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:24:16 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/04 18:25:07 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	cheack_args(const char *format, t_printf *tab)
{
	if (format[tab->index] > '0' && format[tab->index] <= '9')
	{
		while (ft_isdigit(format[tab->index]))
			get_value(&tab->iswidth, &tab->width, format, &tab->index);
	}
	if (format[tab->index] == '-')
	{
		tab->isdash = 1;
		tab->index++;
	}
	if (format[tab->index] == '.')
	{
		tab->ispoint = 1;
		tab->index++;
		while (ft_isdigit(format[tab->index]))
			get_value(&tab->isprecision, &tab->precision, format, &tab->index);
	}
}

void	manage_format(t_printf *tab)
{
	char	*str;
	int		str_size;
	int		w;

	str = va_arg(tab->args, char *);
	str_size = ft_strlen(str);
	if (tab->width > str_size)
		w = tab->width - str_size;
	else
		w = 0;
	if (tab->isdash)
	{
		ft_putstr_fd(str, 1);
		while (w--)
			ft_putchar_fd(' ', 1);
	}
	else if (!tab->isdash)
	{
		while (w--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(str, 1);
	}
}

void	ft_cheack_format(t_printf *tab, const char *format)
{
	tab->index++;
	while (!is_specifier(format[tab->index]))
		cheack_args(format, tab);
	manage_format(tab);
	update_tab(tab);
}

int	ft_printf(const char *format, ...)
{
	int			ret;
	t_printf	*tab;

	tab = (t_printf *)malloc(sizeof(t_printf));
	if (!tab)
		exit (1);
	init_tab(tab);
	va_start(tab->args, format);
	ret = 0;
	while (format[++tab->index])
	{
		if (format[tab->index] == '%')
			ft_cheack_format(tab, format);
		else
			ret += write(1, &format[tab->index], 1);
	}
	va_end(tab->args);
	ret += tab->tl;
	return (free (tab), ret);
}
