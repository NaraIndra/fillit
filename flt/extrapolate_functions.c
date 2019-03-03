/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrapolate_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:30:47 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/03/03 19:17:34 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

int		matrix_extrapolate(t_x *root, int map_size, int init)
{
	t_x *co;

	co = root;
	while ((co = co->r) != root && co->p)
		if (init == 1)
		{
			if (!matrix_extrapolate_right_all(co->d, map_size)
				|| !matrix_extrapolate_down_all(co, map_size))
				return (0);
		}
		else
		{
			if (!matrix_extrapolate_right_one(co)
				|| !matrix_extrapolate_down_one(co))
				return (0);
		}
	return (1);
}

int		matrix_extrapolate_down_one(t_x *co)
{
	t_x		*y;
	t_x		*new;
	int		row;

	y = co;
	row = y->u->l->c->n[0];
	while ((y = y->d) != co)
		if (y->l->c->n[0] == row)
		{
			if (!(new = new_tx(0)))
				return (0);
			insert_up_tx(co, new);
			if (!copy_down(y, new, 1))
				return (0);
		}
	return (1);
}

int		matrix_extrapolate_down_all(t_x *co, int map_size)
{
	t_x		*y;
	t_x		*x;
	t_x		*new;
	int		yc;

	y = co;
	while ((y = y->d) != co)
	{
		x = y;
		yc = 0;
		while ((x = x->r) != y)
			yc = x->c->n[0] > yc ? x->c->n[0] : yc;
		yc = map_size - yc;
		if (yc > 0)
		{
			if (!(new = new_tx(0)))
				return (0);
			insert_up_tx(co, new);
			if (!(copy_down(y, new, 1)))
				return (0);
		}
	}
	return (1);
}

int		matrix_extrapolate_right_one(t_x *co)
{
	t_x		*y;
	t_x		*most_right;
	int		row;

	row = 1;
	y = co;
	most_right = NULL;
	while ((y = y->d) != co)
	{
		if (y->r->c->n[0] != row)
		{
			if (!matrix_insert_right_one(most_right))
				return (0);
			row++;
		}
		most_right = y;
	}
	if (most_right && y == co)
		if (!matrix_insert_right_one(most_right))
			return (0);
	return (1);
}

int		matrix_extrapolate_right_all(t_x *row, int map_size)
{
	t_x		*new;
	t_x		*x;
	int		xc;
	int		i;

	xc = 0;
	x = row;
	while ((x = x->r) != row)
		xc = x->c->n[1] > xc ? x->c->n[1] : xc;
	xc = map_size - xc;
	i = 0;
	while (++i <= xc)
	{
		if (!(new = new_tx(0)))
			return (0);
		insert_up_tx(row->c, new);
		if (!copy_right(row, new, i))
			return (0);
	}
	return (1);
}
