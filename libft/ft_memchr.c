/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:01:51 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/01 19:01:51 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ps;
	unsigned char ucs;

	ps = (unsigned char*)s;
	ucs = (unsigned char)c;
	while (n--)
	{
		if (*ps == ucs)
			return (ps);
		ps++;
	}
	return (NULL);
}
