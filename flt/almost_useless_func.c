/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almost_useless_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 01:06:08 by mstygg            #+#    #+#             */
/*   Updated: 2019/03/02 00:43:57 by mstygg           ###   ########.fr       */
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
static char		*ft_z_ia(int n)
{
	char	s[12];
	int		i;
	long	nl;

	nl = n;
//	if ((sign = nl) < 0)
//		nl = -nl;
	i = 0;
//	if (!nl)
//		s[i++] = '0';
	while (nl)
	{
		s[i++] = nl % 10 + '0';
		nl /= 10;
	}
//	if (sign < 0)
//		s[i++] = '-';
	if(n < 10)
	{
		s[i] = '0';
	}
	s[++i] = '\0';
	ft_strreverse(s);
	return (ft_strdup(s));
}

int					fill_mx(char ***ar, int num)
{
	char	*x;
	//char 	*y;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 1;
	j = 1;
	if (!(*ar))
		return (0);

	while(*((*ar) + count))
	{
		printf("**ar=%p\n", *((*ar) + count));
		getchar();
		if (!(x = ft_z_ia(i)))
			return (0);
		x +=2;
		if (!(x = ft_z_ia(i)))
			return (0);
		x -= 2;
		printf("x=%s\n", x);
		ft_strncpy(*((*ar) + count), x, 4);
		printf("ar+count=%s\n",*((*ar) + count));
		free(x);
		free(x+2);
		if (j > num)
		{
			j = 1;
			++i;
			printf("i=%d, j=%d\n", i, j);
		getchar();
		}
		++count;
	}
	return (1);
}
/*
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
*/
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
		if (!(*(*new)++ = (char*)malloc(5 * sizeof(char))))
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
