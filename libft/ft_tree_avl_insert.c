/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_avl_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:00:53 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/11 20:00:53 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl		*ft_tree_avl_insert(t_avl *r, t_avl *node)
{
	int blc;

	if (!r)
		return (node);
	if (r->key > node->key)
		r->left = ft_tree_avl_insert(r->left, node);
	else if (r->key < node->key)
		r->right = ft_tree_avl_insert(r->right, node);
	r->height = 1 + ft_max(ft_tree_avl_getheight(r->left),
		ft_tree_avl_getheight(r->right));
	if ((blc = ft_tree_avl_getbalance(r)) > 1 && node->key < r->left->key)
		return (ft_tree_avl_rotate_right(r));
	if (blc < -1 && node->key > r->right->key)
		return (ft_tree_avl_rotate_left(r));
	if (blc > 1 && node->key > r->left->key)
	{
		r->left = ft_tree_avl_rotate_left(r->left);
		return (ft_tree_avl_rotate_right(r));
	}
	if (blc < -1 && node->key < r->right->key)
	{
		r->right = ft_tree_avl_rotate_right(r->right);
		return (ft_tree_avl_rotate_left(r));
	}
	return (r);
}
