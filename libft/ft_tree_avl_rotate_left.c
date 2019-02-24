/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_avl_rotate_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:02:52 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/14 19:02:52 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl		*ft_tree_avl_rotate_left(t_avl *x)
{
	t_avl	*y;
	t_avl	*t2;

	y = x->right;
	t2 = y->left;
	y->left = x;
	x->right = t2;
	x->height = 1 + ft_max(ft_tree_avl_getheight(x->left),
		ft_tree_avl_getheight(x->right));
	y->height = 1 + ft_max(ft_tree_avl_getheight(y->left),
		ft_tree_avl_getheight(y->right));
	return (y);
}
