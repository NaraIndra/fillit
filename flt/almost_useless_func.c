/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almost_useless_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 01:06:08 by mstygg            #+#    #+#             */
/*   Updated: 2019/03/01 01:43:41 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

void				cut_src(char **src)
{
	int				i;

	i = 0;
	while (*((*src) + i) == '.' || *((*src) + i) == '\n')
		++i;
	while ((i -= 5) >= 0)
		(*src) += 5;
}

int					c_f(char *filename)
{
	int				fd;
	int				ret;
	char			buf[22];
	int				count;

	count = 0;
	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	while ((ret = read(fd, buf, 21)))
		++count;
	close(fd);
	return (count);
}

int					fill_mx(char ***ar, int num)
{
	int				i;
	int				j;
	char			first;
	char			sec;
	int				count;

	i = 0;
	j = 1;
	first = '1';
	sec = '1';
	count = num * num;
	if (!(*ar))
		return (0);
	while (*((*ar) + i))
	{
		*(*((*ar) + i) + 0) = first;
		*(*((*ar) + i) + 1) = sec++;
		if (sec == (num + 1) + '0')
		{
			sec = '1';
			first++;
		}
		++i;
	}
	return (1);
}

char				***create_ch(char ***new, int num)
{
	char			**tmp;
	int				count;

	count = (num * num);
	if (!(*new = (char**)malloc((count + 1) * sizeof(char*))))
		return (NULL);
	tmp = *new;
	while (count--)
	{
		if (!(*(*new)++ = (char*)malloc(3 * sizeof(char))))
		{
			free_mx(&tmp);
			return (NULL);
		}
	}
	*(*new) = NULL;
	*new = tmp;
	return (new);
}

char				**free_mx(char ***arr)
{
	char			**tmp;

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
