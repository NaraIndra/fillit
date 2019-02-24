/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:22:03 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/03 19:22:03 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *pstart;
	char *pend;
	char *res;

	pstart = (char*)s;
	pend = (char*)s;
	while (ft_iswhitespace(*pstart) && *(pstart))
		pstart++;
	while (*(pend + 1))
		pend++;
	while (ft_iswhitespace(*pend) && pend > s)
		pend--;
	res = pend < pstart ? ft_strnew(pend - s) : ft_strnew(pend - pstart);
	if (!res)
		return (NULL);
	if (pend - s > 0)
		res = ft_strncpy(res, pstart, pend - pstart + 1);
	return (res);
}
