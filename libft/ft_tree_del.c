/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:11:15 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/10 19:11:16 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tree_del(void **node, void (*f)(void *, size_t))
{
	t_bst *temp;

	temp = (t_bst*)*node;
	if (temp->left)
		ft_tree_del((void**)&temp->left, f);
	else if (temp->right)
		ft_tree_del((void**)&temp->right, f);
	f(temp->content, temp->content_size);
	ft_memdel((void **)node);
}
