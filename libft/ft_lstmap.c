/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <mmasstou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:24:22 by mmasstou          #+#    #+#             */
/*   Updated: 2021/11/20 20:14:55 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_resulting;
	t_list	*new_lst;

	if (!f && !del)
		return (NULL);
	lst_resulting = NULL;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&lst_resulting, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_resulting, new_lst);
		lst = lst->next;
	}
	return (lst_resulting);
}
