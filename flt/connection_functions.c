/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:29:57 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/10 00:29:58 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

void	disconnect_secondary_columns(t_x *root)
{
	t_x *x;

	root->dr = root->r;
	root->dl = root->l;
	x = root->r;
	x->dl = x->l;
	x->dr = x->r;
	while ((x = x->r) != root)
	{
		x->dl = x->l;
		x->dr = x->r;
		if (!x->l->p)
		{
			x->l->r = x->l;
			x->l->l = x->l;
		}
	}
	x->l->r = x->l;
	x->l->l = x->l;
	x = x->r;
	while (x->r->p)
		x = x->r;
	x->r = root;
	root->l = x;
}

void	reconnect_secondary_columns(t_x *root)
{
	t_x *co;

	co = root;
	while ((co = co->dr) != root)
	{
		co->r = co->dr;
		co->l = co->dl;
	}
	co->r = co->dr;
	co->l = co->dl;
}
