/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:58:54 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/29 18:58:55 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ps1;
	unsigned char *ps2;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (n && *ps1 && *ps2 && *ps1 == *ps2)
	{
		ps1++;
		ps2++;
		n--;
	}
	return (!n ? 0 : *ps1 - *ps2);
}
