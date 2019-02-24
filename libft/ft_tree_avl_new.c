/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_avl_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:06:26 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/08 21:06:26 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_avl		*ft_tree_avl_new(int k, void *cont, size_t c_size)
{
	t_avl *node;

	node = ft_tree_new(k, cont, c_size, sizeof(*node));
	if (node)
		node->height = 1;
	return (node);
}
