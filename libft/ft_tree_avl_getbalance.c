/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_avl_getbalance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:53:06 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/13 19:53:06 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tree_avl_getbalance(t_avl *n)
{
	if (!n)
		return (0);
	return (ft_tree_avl_getheight(n->left) - ft_tree_avl_getheight(n->right));
}
