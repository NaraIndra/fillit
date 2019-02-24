/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:44:12 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/28 18:44:12 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bitsprint(unsigned n, int format)
{
	int i;

	i = --format;
	while (i >= 0)
	{
		if ((i + 1) % 8 == 0 && i != format)
			ft_putchar(' ');
		ft_putnbr((n >> i) & 1);
		i--;
	}
	ft_putchar('\n');
}
