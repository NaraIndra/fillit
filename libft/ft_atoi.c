/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:20:33 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/11/29 19:20:33 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		if (res * 10 / 10 != res || res * 10 + (*(str) - '0') < 0)
			return (sign > 0 ? -1 : 0);
		res = res * 10 + (*(str++) - '0');
	}
	return (res * sign);
}
