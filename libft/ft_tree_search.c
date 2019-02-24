/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:53:15 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/09 18:53:15 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_tree_search(void *node, int key)
{
	t_bst *n;

	n = node;
	while (n && n->key != key)
	{
		if (key > n->key)
			n = n->right;
		else
			n = n->left;
	}
	return (n);
}
