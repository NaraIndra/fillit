/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:29:44 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/10 00:29:45 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

t_x		*find_column_object_by_name(t_x *root, char *name)
{
	t_x *t;

	t = root;
	while ((t = t->r) != root)
		if (ft_strcmp(t->n, name) == 0)
			return (t);
	return (NULL);
}

int		in_arr(t_x *e, t_x *arr[], int *size)
{
	int i;

	i = 0;
	while (i < *size && arr[i])
	{
		if (arr[i] == e)
			return (1);
		i++;
	}
	return (0);
}

/*
** ft_strlen(src) can be replaced by const
*/

int		is_connected(char *src)
{
	int connects;
	int i;
	int length;

	connects = 0;
	i = 0;
	length = ft_strlen(src);
	while (*src)
	{
		i++;
		if (*src == '#')
		{
			if (length - i >= 5 && *(src + 5) == '#')
				connects++;
			if (i >= 5 && *(src - 5) == '#')
				connects++;
			if (i >= 1 && *(src - 1) == '#')
				connects++;
			if (length - i >= 1 && *(src + 1) == '#')
				connects++;
		}
		src++;
	}
	return (connects < 6 ? 0 : 1);
}

int		is_valid(char *str)
{
	int i;
	int	pieces;

	i = 0;
	pieces = 0;
	if (ft_strlen(str) < 20)
		return (0);
	while (str[i])
	{
		if ((i + 1) % 5 == 0 || i == 20)
		{
			if (str[i] != '\n')
				return (0);
		}
		else if (str[i] != '#' && str[i] != '.')
			return (0);
		pieces += str[i] == '#' ? 1 : 0;
		i++;
	}
	return (pieces == 4 && is_connected(str) ? 1 : 0);
}

void	clear_structure(t_x **root)
{
	t_x *x;
	t_x *y;
	t_x *r;

	r = *root;
	x = r->r;
	while (x != r)
	{
		y = x->d;
		while (y != x)
		{
			y = y->d;
			free(y->u);
		}
		x = x->r;
		free(x->l);
	}
	free(*root);
	*root = NULL;
}
