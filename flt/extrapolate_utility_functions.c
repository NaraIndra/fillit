/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrapolate_utility_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:30:56 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/10 00:30:57 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

int		copy_down(t_x *row, t_x *new_row, int xc)
{
	t_x		*x;
	t_x		*co;
	t_x		*new;
	char	name[3];

	name[2] = 0;
	x = row;
	while ((x = x->r) != row)
	{
		ft_strcpy(name, x->c->n);
		name[0] += xc;
		co = find_column_object_by_name(row->c, name);
		if (!(new = new_tx(0)))
			return (0);
		insert_up_tx(co, new);
		insert_left_tx(new_row, new);
	}
	return (1);
}

int		copy_right(t_x *row, t_x *new_row, int xc)
{
	t_x		*x;
	t_x		*co;
	t_x		*new;
	char	name[3];

	name[2] = 0;
	x = row;
	while ((x = x->r) != row)
	{
		ft_strcpy(name, x->c->n);
		name[1] += xc;
		co = find_column_object_by_name(row->c, name);
		if (!(new = new_tx(0)))
			return (0);
		insert_up_tx(co, new);
		insert_left_tx(new_row, new);
	}
	return (1);
}

int		matrix_insert_right_one(t_x *most_right)
{
	t_x *new;

	if (!(new = new_tx(0)))
		return (0);
	insert_down_tx(most_right, new);
	if (!copy_right(most_right, new, 1))
		return (0);
	return (1);
}
