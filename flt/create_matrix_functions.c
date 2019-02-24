/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:30:11 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/10 00:30:12 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

static char		*g_cols[17] = {"11", "12", "13", "14", "21", "22", "23",\
	"24", "31", "32", "33", "34", "41", "42", "43", "44", 0};

t_x		*create_root(void)
{
	t_x *root;

	if (!(root = new_tx("h")))
		return (NULL);
	root->d = NULL;
	root->u = NULL;
	return (root);
}

int		create_column_objects(t_x *root)
{
	int		i;
	t_x		*new;

	i = 0;
	while (g_cols[i])
	{
		if (!(new = new_tx(g_cols[i])))
		{
			clear_structure(&root);
			return (-1);
		}
		insert_left_tx(root, new);
		i++;
	}
	return (1);
}

t_x		*append_figure_type_column(t_x *root, char *figure)
{
	t_x *new;

	if (!(new = new_tx(figure)))
		return (NULL);
	while (root->r->p)
		root = root->r;
	insert_right_tx(root, new);
	return (root->r);
}

int		insert_figure(t_x *root, t_x *row, char *line)
{
	int		i;
	int		p;
	t_x		*co;
	t_x		*new;

	p = 0;
	i = 0;
	while (p != 4 && *line)
	{
		if (*line == '1')
		{
			co = find_column_object_by_name(root, g_cols[i]);
			if (!(new = new_tx(0)))
				return (0);
			insert_up_tx(co, new);
			insert_left_tx(row, new);
			p++;
		}
		line++;
		i++;
	}
	return (1);
}

int		create_matrix_row(t_x *root, char *figure, char *line)
{
	t_x *t;
	t_x *new;

	if (!(t = find_column_object_by_name(root, figure)))
		t = append_figure_type_column(root, figure);
	if (!t || !(new = new_tx(0)))
		return (0);
	t = insert_up_tx(t, new);
	return (insert_figure(root, t, line));
}
