/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:46:35 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/28 18:46:36 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sortshell(int *arr, size_t size)
{
	int gap;
	int i;
	int j;
	int temp;

	gap = size / 2;
	while (gap > 0)
	{
		i = gap;
		while ((size_t)i < size)
		{
			j = i - gap;
			while (j >= 0 && arr[j] > arr[j + gap])
			{
				temp = arr[j];
				arr[j] = arr[j + gap];
				arr[j + gap] = temp;
				j -= gap;
			}
			i++;
		}
		gap /= 2;
	}
}
