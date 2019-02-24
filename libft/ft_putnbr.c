/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:13:15 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/02 18:13:15 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_recursive(int n)
{
	if (n / 10 == 0)
	{
		n = n < 0 ? n * -1 + '0' : n + '0';
		ft_putchar(n);
		return ;
	}
	else
		ft_recursive(n / 10);
	n = n % 10;
	n = n < 0 ? n * -1 + '0' : n + '0';
	ft_putchar(n);
}

void			ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_recursive(n);
}
