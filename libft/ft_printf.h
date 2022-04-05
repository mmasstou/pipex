/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:13:03 by mmasstou          #+#    #+#             */
/*   Updated: 2022/04/05 12:13:50 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_printf
{
	va_list	args;
	int		tl;
	int		isdash;
	int		ispoint;
	int		iswidth;
	int		isprecision;
	int		width;
	int		precision;
	int		index;

}	t_printf;

int			is_specifier(int character);
t_printf	*init_tab(t_printf *tab);
t_printf	*update_tab(t_printf *tab);
void		cheack_args(const char *format, t_printf *tab);
void		manage_format(t_printf *tab);
void		ft_cheack_format(t_printf *tab, const char *format);
void		get_value(int *is, int *value, const char *format, int *index);
#endif