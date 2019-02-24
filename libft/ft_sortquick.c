/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortquick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:37:53 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/28 19:37:54 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_part(int *arr, int start, int end)
{
	int pivot;

	pivot = arr[(start + end) / 2];
	while (1)
	{
		while (arr[start] < pivot)
			start++;
		while (arr[end] > pivot)
			end--;
		if (start >= end)
			return (end);
		ft_swap(&arr[start], &arr[end]);
	}
}

static void	ft_sqrec(int *arr, int start, int end)
{
	int pos;

	if (start < end)
	{
		pos = ft_part(arr, start, end);
		ft_sqrec(arr, start, pos);
		ft_sqrec(arr, pos + 1, end);
	}
}

void		ft_sortquick(int *arr, size_t size)
{
	ft_sqrec(arr, 0, size - 1);
}
