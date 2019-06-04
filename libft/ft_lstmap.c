/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:18:33 by jwinthei          #+#    #+#             */
/*   Updated: 2018/11/28 18:48:06 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;

	if (!lst || !(list = ft_lstnew(NULL, 0)))
		return (NULL);
	list = f(lst);
	tmp = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = ft_lstnew(NULL, 0)))
		{
			while (tmp->next)
			{
				list = tmp;
				tmp = tmp->next;
				free(list);
			}
			return (NULL);
		}
		list->next = f(lst);
		list = list->next;
	}
	return (tmp);
}
