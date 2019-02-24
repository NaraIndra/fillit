/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_avl_rotate_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:31:50 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/13 20:31:50 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl		*ft_tree_avl_rotate_right(t_avl *y)
{
	t_avl	*x;
	t_avl	*t2;

	x = y->left;
	t2 = x->right;
	x->right = y;
	y->left = t2;
	y->height = 1 + ft_max(ft_tree_avl_getheight(y->left),
		ft_tree_avl_getheight(y->right));
	x->height = 1 + ft_max(ft_tree_avl_getheight(x->left),
		ft_tree_avl_getheight(x->right));
	return (x);
}
