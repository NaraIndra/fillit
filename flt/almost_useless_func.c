/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almost_useless_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 01:06:08 by mstygg            #+#    #+#             */
/*   Updated: 2019/03/03 19:29:31 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

void					cut_src(unsigned char **src)
{
	int					i;

	i = 0;
	while (*((*src) + i) == '.' || *((*src) + i) == '\n')
		++i;
	while ((i -= 5) >= 0)
		(*src) += 5;
}

int						c_f(char *filename)
{
	int					fd;
	int					ret;
	unsigned char		buf[22];
	int					count;

	count = 0;
	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	while ((ret = read(fd, buf, 21)))
		++count;
	close(fd);
	return (count);
}

int						fill_mx(unsigned char ***ar, int num)
{
	int					count;
	unsigned char		i;
	unsigned char		j;

	count = 0;
	i = 1;
	j = 1;
	if (!ar)
		return (0);
	while (*((*ar) + count))
	{
		*(*((*ar) + count) + 0) = i;
		*(*((*ar) + count) + 1) = j;
		if (j++ == num)
		{
			j = 1;
			++i;
		}
		++count;
	}
	return (1);
}

unsigned char			***create_ch(unsigned char ***new, int num)
{
	unsigned char		**tmp;
	int					count;

	count = (num * num);
	if (!(*new = (unsigned char**)malloc((count + 1) * sizeof(unsigned char*))))
		return (NULL);
	tmp = *new;
	while (count--)
	{
		if (!(*(*new)++ = (unsigned char*)malloc(2 * sizeof(unsigned char))))
		{
			free_mx(&tmp);
			return (NULL);
		}
	}
	*(*new) = NULL;
	*new = tmp;
	return (new);
}

unsigned char			**free_mx(unsigned char ***arr)
{
	unsigned char		**tmp;

	tmp = *arr;
	if (!tmp)
		return (NULL);
	while (*tmp)
	{
		free(*tmp);
		*tmp++ = NULL;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}
