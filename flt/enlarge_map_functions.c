/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enlarge_map_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:30:23 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/03/01 22:51:40 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

int		get_m_s_structure(t_x *root)
{
	t_x *co;
	t_x *y;
	t_x *x;
	int	max;

	max = 0;
	co = root;
	while ((co = co->r) != root && co->p)
	{
		y = co;
		while ((y = y->d) != co)
		{
			x = y;
			while ((x = x->r) != y)
			{
				max = max < x->c->n[0] - '0' ? x->c->n[0] - '0' : max;
				max = max < x->c->n[1] - '0' ? x->c->n[1] - '0' : max;
			}
		}
	}
	return (max);
}

void	adjust_matrix(t_x *root, int map_size)
{
	t_x *co;

	if (map_size > 4)
		return ;
	co = root;
	while ((co = co->r) != root)
	{
		if (co->p)
			continue ;
		if (co->n[0] - '0' > map_size || co->n[1] - '0' > map_size)
		{
			co->r->l = co->l;
			co->l->r = co->r;
			free(co);
		}
	}
}

int		enlarge_map(t_x *root, int map_size)
{
	reconnect_secondary_columns(root);
	if (!add_columns(root, map_size) || !add_row(root, map_size))
		return (0);
	matrix_extrapolate(root, map_size, 0);
	disconnect_secondary_columns(root);
	return (1);
}

int		add_columns(t_x *root, int map_size)
{
	t_x		*x;
	t_x		*new;
	char	map_row;
	char	name[3];

	name[2] = 0;
	map_row = '1';
	x = root;
	while ((x = x->r) != root)
	{
		if (x->p || x->c->n[0] == map_row)
			continue ;
		name[0] = map_row++;
		name[1] = map_size + '0';
		if (!(new = new_tx(name)))
			return (0);
		insert_left_tx(x, new);
	}
	name[0] = map_row++;
	name[1] = map_size + '0';
	if (!(new = new_tx(name)))
		return (0);
	insert_left_tx(x, new);
	return (1);
}

int		add_row(t_x *root, int map_size)
{
	t_x		*new;
	int		i;
	char	name[3];

	name[0] = map_size + '0';
	name[2] = 0;
	i = 1;
	while (i <= map_size)
	{
		name[1] = i++ + '0';
		if (!(new = new_tx(name)))
			return (0);
		insert_left_tx(root, new);
	}
	return (1);
}
