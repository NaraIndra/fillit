/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:27:11 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/28 19:27:12 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dl;
	int		i;

	i = -1;
	dl = ft_strlen(dst);
	if (size > dl + 1)
	{
		while (*dst)
			dst++;
		while (*(src + ++i) && (size_t)i < size - dl - 1)
			*(dst + i) = *(src + i);
		*(dst + i) = '\0';
	}
	dl = dl > size ? size : dl;
	return (dl + ft_strlen(src));
}
