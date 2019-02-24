/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_avl_delone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:57:55 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/14 19:57:55 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_avl	*min_value_node(t_avl *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

static t_avl	*relink(t_avl *node, t_avl *node_next)
{
	free(node->content);
	free(node);
	return (node_next);
}

static void		copy_content(t_avl *root, t_avl *temp)
{
	root->key = temp->key;
	free(root->content);
	root->content = temp->content;
	root->content_size = temp->content_size;
}

static t_avl	*avl_balance(t_avl *root, int balance)
{
	if (balance >= -1 && balance <= 1)
		return (root);
	if (balance > 1 && ft_tree_avl_getbalance(root->left) >= 0)
		return (ft_tree_avl_rotate_right(root));
	if (balance > 1 && ft_tree_avl_getbalance(root->left) < 0)
	{
		root->left = ft_tree_avl_rotate_left(root->left);
		return (ft_tree_avl_rotate_right(root));
	}
	if (balance < -1 && ft_tree_avl_getbalance(root->right) <= 0)
		return (ft_tree_avl_rotate_left(root));
	if (balance < -1 && ft_tree_avl_getbalance(root->right) > 0)
	{
		root->right = ft_tree_avl_rotate_right(root->right);
		return (ft_tree_avl_rotate_left(root));
	}
	return (root);
}

t_avl			*ft_tree_avl_delone(t_avl *root, int key)
{
	t_avl	*t;
	int		balance;

	if (!root)
		return (NULL);
	if (key < root->key)
		root->left = ft_tree_avl_delone(root->left, key);
	else if (key > root->key)
		root->right = ft_tree_avl_delone(root->right, key);
	else
	{
		if (!root->left)
			return (relink(root, root->right));
		if (!root->right)
			return (relink(root, root->left));
		t = min_value_node(root->right);
		copy_content(root, t);
		root->right = ft_tree_avl_delone(root->right, t->key);
	}
	root->height = 1 + ft_max(ft_tree_avl_getheight(root->left),
		ft_tree_avl_getheight(root->right));
	balance = ft_tree_avl_getbalance(root);
	if (balance >= -1 && balance <= 1)
		return (root);
	return (avl_balance(root, balance));
}
