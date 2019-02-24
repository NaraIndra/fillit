/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:11:53 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/06 19:11:54 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoaws(int n, int width, char symbol)
{
	char	s[width + 1];
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
		if (i == width - (sign < 0 ? 1 : 0))
			return (ft_strdup("-1"));
		s[i++] = nl % 10 + '0';
		nl /= 10;
	}
	if (sign < 0)
		s[i++] = '-';
	while (i < width)
		s[i++] = symbol;
	s[i] = '\0';
	ft_strreverse(s);
	return (ft_strdup(s));
}
