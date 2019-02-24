/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:01:35 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/01 17:01:35 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ucd;
	unsigned char *us;

	ucd = dst;
	us = (unsigned char *)src;
	while (n--)
	{
		*ucd = *us;
		if (*ucd == (unsigned char)c)
			return (++ucd);
		ucd++;
		us++;
	}
	return (NULL);
}
