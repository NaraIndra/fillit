/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:17:41 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/29 17:17:41 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ps;

	ps = (char*)s;
	while (*ps)
		ps++;
	while (*ps != c && ps != s)
		ps--;
	if (*ps != c)
		return (NULL);
	return (ps);
}
