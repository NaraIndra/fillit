/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortinsertion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:45:36 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/28 18:45:36 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sortinsertion(int *arr, size_t size)
{
	int i;
	int j;

	i = 1;
	while ((size_t)i < size)
	{
		j = i;
		while (arr[j] < arr[j - 1] && j >= 0)
		{
			ft_swap(&arr[j], &arr[j - 1]);
			j--;
		}
		i++;
	}
}
