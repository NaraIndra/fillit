/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:32:57 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/29 17:32:58 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	char *r;
	char *nc;

	nc = (char*)n;
	if (ft_strcmp(n, "") == 0)
		return ((char*)h);
	while (*h)
	{
		if (*h == *nc)
		{
			r = (char*)h;
			while (*h == *nc && *h && *nc)
			{
				h++;
				nc++;
			}
			if (*nc == '\0' && *(h - 1) == *(nc - 1))
				return (r);
			h = r;
			nc = (char*)n;
		}
		h++;
	}
	return (NULL);
}
