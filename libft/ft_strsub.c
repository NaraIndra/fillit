/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:31:23 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/03 18:31:24 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ptr;
	char *pptr;

	ptr = ft_strnew(len);
	if (!ptr)
		return (NULL);
	pptr = ptr;
	while (start--)
		s++;
	while (len--)
		*pptr++ = *s++;
	return (ptr);
}
