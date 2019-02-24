/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:49:46 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/03 17:49:46 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ptr;
	char *pptr;

	ptr = ft_strnew(ft_strlen(s));
	if (!ptr)
		return (NULL);
	pptr = ptr;
	while (*s)
		*pptr++ = f(*s++);
	return (ptr);
}
