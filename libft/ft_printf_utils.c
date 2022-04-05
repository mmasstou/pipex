/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:14:21 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/05 12:15:43 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	get_value(int *is, int *value, const char *format, int *index)
{
	*is = 1;
	*value = *value * 10 + format[*index] - 48;
	(*index)++;
}

int	is_specifier(int character)
{
	char	*specifiers;

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
