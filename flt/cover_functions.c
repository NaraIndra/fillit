/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:29:36 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/10 00:29:37 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

void	cover_column(t_x *c)
{
	t_x *i;
	t_x *j;

	c->r->l = c->l;
	c->l->r = c->r;
	i = c;
	while ((i = i->d) != c)
	{
		j = i;
		while ((j = j->r) != i)
		{
			j->d->u = j->u;
			j->u->d = j->d;
		}
	}
}

void	uncover_column(t_x *c)
{
	t_x *i;
	t_x *j;

	i = c;
	while ((i = i->u) != c)
	{
		j = i;
		while ((j = j->l) != i)
		{
			j->d->u = j;
			j->u->d = j;
		}
	}
	c->r->l = c;
	c->l->r = c;
}

void	cover_inner_columns(t_x *r)
{
	t_x *j;

	j = r;
	while ((j = j->r) != r)
		cover_column(j->c);
}

void	uncover_inner_columns(t_x *r)
{
	t_x *j;

	j = r;
	while ((j = j->l) != r)
		uncover_column(j->c);
}
