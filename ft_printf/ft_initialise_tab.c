/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:46:35 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/01 13:27:09 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*ft_initialise_tab(t_printf *tab)
{
	tab->tl = 0;
	tab->plus = 0;
	tab->_rep->plus = 0;
	tab->perc = 0;
	tab->_rep->perc = 0;
	tab->space = 0;
	tab->_rep->space = 0;
	tab->shrap = 0;
	tab->_rep->shrap = 0;
	tab->is_flag = 0;
	tab->_rep->flags = 0;
	tab->zero = 0;
	tab->_rep->zero = 0;
	tab->dash = 0;
	tab->_rep->dash = 0;
	tab->pnt = 0;
	tab->_rep->pnt = 0;
	tab->width = 0;
	tab->_rep->width = 0;
	tab->precision = 0;
	tab->_rep->precision = 0;
	return (tab);
}
