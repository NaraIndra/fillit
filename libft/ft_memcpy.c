/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:18:27 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/30 19:18:27 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ucd;
	unsigned char *us;

	if (dst == src)
		return (dst);
	ucd = dst;
	us = (unsigned char *)src;
	while (n--)
		*ucd++ = *us++;
	return (dst);
}
