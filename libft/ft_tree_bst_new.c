/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_bst_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:58:45 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/29 18:58:45 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bst		*ft_tree_bst_new(int k, void *cont, size_t c_size)
{
	return (ft_tree_new(k, cont, c_size, sizeof(t_bst)));
}
