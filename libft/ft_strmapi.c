/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:05:05 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/03 18:05:05 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = ft_strnew(ft_strlen(s));
	if (!ptr)
		return (NULL);
	while (*(s + i))
	{
		*(ptr + i) = f(i, *(s + i));
		i++;
	}
	return (ptr);
}
