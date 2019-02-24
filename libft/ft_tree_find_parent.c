/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_find_parent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:38:31 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/12 20:38:32 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_tree_find_parent(void *node, int key)
{
	t_bst *n;
	t_bst *p;

	n = node;
	p = NULL;
	while (n && n->key != key)
	{
		p = n;
		if (key > n->key)
			n = n->right;
		else
			n = n->left;
	}
	return (p);
}
