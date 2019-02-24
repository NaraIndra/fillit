/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:33:54 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/12 19:33:54 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstrw(char const *s, size_t width, char c)
{
	size_t	before;
	size_t	after;
	size_t	s_length;

	s_length = ft_strlen(s);
	before = (width - s_length) / 2;
	after = before;
	while (after * 2 < width - s_length)
		after++;
	ft_putcharn(c, before);
	write(1, s, s_length);
	ft_putcharn(c, after);
}
