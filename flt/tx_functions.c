/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:29:26 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/03/03 16:16:54 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

t_x		*new_tx(const unsigned char *name)
{
	t_x		*link;

	link = malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->n[0] = name ? name[0] : 0;
	link->n[1] = name ? name[1] : 0;
	link->l = link;
	link->r = link;
	link->u = link;
	link->d = link;
	link->c = link;
	link->p = name && ft_ustrlen(name) < 2 && ft_isupper(*name) ? 1 : 0;
	link->dr = name ? link : NULL;
	link->dl = name ? link : NULL;
	return (link);
}

t_x		*insert_right_tx(t_x *root, t_x *new)
{
	new->r = root->r;
	root->r->l = new;
	root->r = new;
	new->l = root;
	return (new);
}

t_x		*insert_left_tx(t_x *root, t_x *new)
{
	new->l = root->l;
	root->l->r = new;
	root->l = new;
	new->r = root;
	return (new);
}

t_x		*insert_up_tx(t_x *root, t_x *new)
{
	new->u = root->u;
	root->u->d = new;
	root->u = new;
	new->d = root;
	new->c = root->c;
	return (new);
}

t_x		*insert_down_tx(t_x *root, t_x *new)
{
	new->d = root->d;
	root->d->u = new;
	root->d = new;
	new->u = root;
	new->c = root->c;
	return (new);
}
