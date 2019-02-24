/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:00:38 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/27 20:00:38 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*temp;

	ptr = ft_strnew(ft_strlen(s1));
	if (!ptr)
		return (NULL);
	temp = ptr;
	ft_strcpy(temp, (char*)s1);
	return (ptr);
}
