/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utility_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:50:58 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/10 22:50:58 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

void	print_row(t_x *row)
{
	t_x *x;

	x = row;
	ft_putchar('(');
	ft_putstr(x->c->n);
	ft_putstr("), ");
	while ((x = x->r) != row)
	{
		ft_putchar('(');
		ft_putstr(x->c->n);
		ft_putstr("), ");
	}
	ft_putchar('\n');
}

void	print_column_objects(t_x *root)
{
	t_x *t;

	t = root;
	if (root->r != root)
		ft_putstr("h, ");
	else
		ft_putchar('h');
	while ((t = t->r) != root)
	{
		if (t->p)
			ft_putstr("[p]");
		ft_putstr(t->n);
		if (t->r != root)
			ft_putstr(", ");
	}
	ft_putchar('\n');
}

void	print_structure(t_x *root)
{
	t_x		*co;
	t_x		*r;
	t_x		*x;

	print_column_objects(root);
	co = root;
	while ((co = co->r) != root && co->p)
	{
		r = co;
		while ((r = r->d) != co)
		{
			ft_putchar('(');
			ft_putstr(r->c->n);
			ft_putchar(')');
			x = r;
			while ((x = x->r) != r)
			{
				ft_putchar('(');
				ft_putstr(x->c->n);
				ft_putchar(')');
			}
			ft_putchar('\n');
		}
	}
}

/*
** print_solution_as_structure: debug function
*/

int		print_solution_as_structure(t_list *solution)
{
	t_x		*r;
	t_list	*t;

	t = solution;
	ft_putendl("solution:");
	while (t)
	{
		r = (t_x*)t->content;
		ft_putchar('(');
		ft_putstr(r->c->n);
		ft_putstr("), ");
		while ((r = r->r) != (t_x*)t->content)
		{
			ft_putchar('(');
			ft_putstr(r->c->n);
			ft_putstr("), ");
		}
		ft_putchar('\n');
		t = t->next;
	}
	ft_putchar('\n');
	return (1);
}
