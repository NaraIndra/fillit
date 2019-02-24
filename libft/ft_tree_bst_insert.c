/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_bst_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:24:47 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/13 19:24:48 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst		*ft_tree_bst_insert(t_bst *root, t_bst *node)
{
	if (!root)
		return (node);
	if (root->key > node->key)
		root->left = ft_tree_bst_insert(root->left, node);
	else if (root->key < node->key)
		root->right = ft_tree_bst_insert(root->right, node);
	return (root);
}
