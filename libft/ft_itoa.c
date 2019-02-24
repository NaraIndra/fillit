/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:47:33 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/05 18:47:34 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	s[12];
	int		sign;
	int		i;
	long	nl;

	nl = n;
	if ((sign = nl) < 0)
		nl = -nl;
	i = 0;
	if (!nl)
		s[i++] = '0';
	while (nl)
	{
		s[i++] = nl % 10 + '0';
		nl /= 10;
	}
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	ft_strreverse(s);
	return (ft_strdup(s));
}
