/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:46:52 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/10 17:46:52 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*temp;

	if (!(temp = f(lst)))
		return (NULL);
	start = temp;
	while ((lst = lst->next))
	{
		if (!(temp->next = f(lst)))
		{
			ft_lstdel(&start, ft_del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (start);
}
