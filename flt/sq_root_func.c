/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_root_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 01:23:47 by mstygg            #+#    #+#             */
/*   Updated: 2019/03/01 01:24:53 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

double		ft_abs(double n)
{
	return (n >= 0) ? (n) : (-n);
}

int			f_s(int nb)
{
	double	x_n;
	double	b;
	double	x_n_1;

	if (nb >= 0)
	{
		x_n = 1;
		b = nb;
		x_n_1 = nb;
		while (ft_abs(x_n_1 - x_n) > EPS)
		{
			x_n = (x_n + b) / 2;
			b = nb / x_n;
			x_n_1 = (x_n + b) / 2;
		}
		return (x_n_1);
	}
	return (-1);
}
