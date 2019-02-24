/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:08:37 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/29 18:08:37 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	char *ph;
	char *pn;
	char *r;

	ph = (char*)h;
	pn = (char*)n;
	if (ft_strcmp(pn, "") == 0)
		return (ph);
	while (*ph && ph != h + len)
	{
		if (*ph == *pn)
		{
			r = ph;
			while (ph != h + len && *ph && *pn && *ph++ == *pn++)
				;
			if (*pn == '\0' && *(ph - 1) == *(pn - 1))
				return (r);
			ph = r;
			pn = (char*)n;
		}
		ph++;
	}
	return (NULL);
}
