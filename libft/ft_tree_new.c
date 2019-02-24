/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:46:31 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/09 18:46:31 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_tree_new(int k, void *cont, size_t c_size, size_t n_size)
{
	t_bst *node;

	if (!(node = malloc(n_size)))
		return (NULL);
	if (cont == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if (!(node->content = ft_memalloc(c_size)) || c_size == 0)
		{
			ft_tree_del((void**)&node, ft_del);
			return (NULL);
		}
		ft_memcpy(node->content, cont, c_size);
		node->content_size = c_size;
	}
	node->key = k;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
