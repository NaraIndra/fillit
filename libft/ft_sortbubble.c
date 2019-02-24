/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbubble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:46:27 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/28 18:46:28 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sortbubble(int *arr, size_t size)
{
	int i;
	int swapped;

	while (size >= 1)
	{
		swapped = 0;
		i = 0;
		while ((size_t)i + 1 < size)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break ;
		size--;
	}
}
