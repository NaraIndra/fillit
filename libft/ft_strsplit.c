/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:45:24 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/04 16:45:25 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_freeaptr(char **aptr, size_t elems)
{
	if (*aptr)
		ft_freearray((void**)aptr, elems);
	else
		free(aptr);
}

static char		**ft_memrealloc(char **aptr, size_t e, char const *s, size_t l)
{
	char	**pptr;

	pptr = ft_memalloc(sizeof(char*) * (e + 1));
	if (!pptr)
	{
		ft_freeaptr(aptr, e);
		return (NULL);
	}
	*(pptr + e) = NULL;
	*(pptr + e - 1) = ft_strnew(l);
	if (!*(pptr + e - 1))
	{
		ft_freeaptr(aptr, e - 1);
		free(pptr);
		return (NULL);
	}
	while (l--)
		*(*(pptr + e - 1) + l) = *(s + l);
	while (e-- - 1)
		*(pptr + e - 1) = *(aptr + e - 1);
	free(aptr);
	return (pptr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	ctr;
	size_t	arr_elems;

	arr = ft_memalloc(sizeof(char*));
	if (!arr)
		return (NULL);
	*arr = NULL;
	arr_elems = 1;
	while (*s)
	{
		ctr = 0;
		while (*(s + ctr) != c && *(s + ctr))
			ctr++;
		if (ctr)
		{
			arr = ft_memrealloc(arr, arr_elems, s, ctr);
			if (!arr)
				return (NULL);
			arr_elems++;
		}
		s += ctr == 0 ? 1 : ctr;
	}
	return (arr);
}
