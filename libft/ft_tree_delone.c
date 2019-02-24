/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:48:16 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/14 19:48:16 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*min_value_node(void *root)
{
	t_bst *node;

	node = root;
	while (node->left)
		node = node->left;
	return (node);
}

static void	*relink(void *node, void *node_next)
{
	free(((t_bst*)node)->content);
	free(node);
	return (node_next);
}

static void	copy_content(void *root, void *temp)
{
	t_bst *r;
	t_bst *t;

	r = root;
	t = temp;
	r->key = t->key;
	free(r->content);
	r->content = t->content;
	r->content_size = t->content_size;
}

void		*ft_tree_delone(void *root, int key)
{
	t_bst *r;
	t_bst *t;

	if (!root)
		return (NULL);
	r = root;
	if (key < r->key)
		r->left = ft_tree_delone(r->left, key);
	else if (key > r->key)
		r->right = ft_tree_delone(r->right, key);
	else
	{
		if (!r->left)
			return (relink(r, r->right));
		if (!r->right)
			return (relink(r, r->left));
		t = min_value_node(r->right);
		copy_content(r, t);
		r->right = ft_tree_delone(r->right, t->key);
	}
	return (r);
}
