/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:45:21 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/02 18:45:22 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_recursive(int n, int fd)
{
	if (n / 10 == 0)
	{
		n = n < 0 ? n * -1 + '0' : n + '0';
		ft_putchar_fd(n, fd);
		return ;
	}
	else
		ft_recursive(n / 10, fd);
	n = n % 10;
	n = n < 0 ? n * -1 + '0' : n + '0';
	ft_putchar_fd(n, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_recursive(n, fd);
}
