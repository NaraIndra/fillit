/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:26:07 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/02 19:26:07 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*pstr;

	if (size + 1 == 0)
		return (NULL);
	pstr = (char*)malloc(sizeof(char) * (size + 1));
	if (!pstr)
		return (NULL);
	ft_memset(pstr, '\0', size + 1);
	return (pstr);
}
