/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:20:42 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/28 17:20:42 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (*(src + i) && i < len)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	while (i < len)
		*(dst + i++) = '\0';
	return (dst);
}
