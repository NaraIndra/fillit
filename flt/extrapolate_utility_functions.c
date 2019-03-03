/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrapolate_utility_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:30:56 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/03/03 18:53:32 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

int		copy_down(t_x *row, t_x *new_row, int xc)
{
	t_x		*x;
	t_x		*co;
	t_x		*new;
	unsigned char	name[2];

	x = row;
	while ((x = x->r) != row)
	{
		name[0] = x->c->n[0] + xc;
		name[1] = x->c->n[1];
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
	unsigned char	name[2];

	x = row;
	name[0] = x->c->n[0];
	name[1] = x->c->n[1];
	while ((x = x->r) != row)
	{
		name[0] = x->c->n[0];
		name[1] = x->c->n[1] + xc;
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