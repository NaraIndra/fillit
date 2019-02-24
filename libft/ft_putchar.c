/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:02:43 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/02 18:02:43 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned int first_byte;
	unsigned int second_byte;

	if (c < 0)
	{
		first_byte = (128 + 64) | ((c & 255) >> 6);
		second_byte = 128 | (~(~(unsigned)0 << 6) & c);
		write(1, &first_byte, 1);
		write(1, &second_byte, 2);
	}
	else
		write(1, &c, 1);
}
