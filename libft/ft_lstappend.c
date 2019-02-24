/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:03:49 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/10 19:03:50 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstappend(t_list *start, t_list *new)
{
	if (!start)
		return (new);
	while (start->next)
		start = start->next;
	start->next = new;
	return (start->next);
}
