/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_bst_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 20:10:30 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/29 20:10:31 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_add_item(t_bst *node, t_list **start)
{
	t_list *new;

	new = ft_lstnew(node ? &node->key : ft_memalloc(sizeof(0)),
		node ? sizeof(node->key) : sizeof(0));
	if (!new)
		return (NULL);
	ft_lstappend(*start, new);
	return (new);
}

static int			ft_is_end(t_list *start, int length)
{
	t_list	*temp;
	int		c;

	c = length;
	while ((c & 1) && c)
		c = c >> 1;
	if (c == 0)
	{
		c = length - (length >> 1);
		temp = start;
		while (length-- - c)
			temp = temp->next;
		while (c)
		{
			if (*(int*)temp->content != 0)
				break ;
			temp = temp->next;
			c--;
		}
	}
	return (c ? 0 : 1);
}

static int			ft_create_list(t_bst *r, t_list **s, int *l, t_list **last)
{
	t_list			*temp;
	t_bst			*node;

	temp = *last ? (*last)->next : *s;
	*last = temp;
	node = ft_tree_search((void*)r, *(int*)temp->content);
	if (!ft_add_item(node ? node->left : NULL, s) ||
		!ft_add_item(node ? node->right : NULL, s))
		return (0);
	*l += 2;
	if (ft_is_end(*s, *l))
		return (1);
	ft_create_list(r, s, l, last);
	return (1);
}

static void			ft_print_tree(t_list *s, int l, int io, size_t n_w)
{
	int		i;
	int		c;
	int		base_width;
	char	*print;

	i = 1;
	base_width = (l - (l >> 1)) * n_w * 2 - 1;
	while ((i = l & i))
	{
		ft_putcharn(' ', (io >> 1) * n_w);
		c = i;
		while (c--)
		{
			print = ft_itoaws(*(int*)s->content, n_w, ' ');
			ft_putstr(print);
			free(print);
			if (c)
				ft_putcharn(' ', io * n_w);
			s = s->next;
		}
		ft_putcharn(' ', (io >> 1) * n_w);
		ft_putchar('\n');
		i <<= 1;
		io >>= 1;
	}
}

void				ft_tree_bst_print(t_bst *root)
{
	t_list	*start;
	t_list	*t;
	int		length;
	size_t	max_nbr_width;
	size_t	width;

	if (!root)
	{
		ft_putendl_fd("The tree is empty.", 2);
		return ;
	}
	length = 1;
	if (!(start = ft_lstnew(&root->key, sizeof(&root->key))))
		return ;
	t = NULL;
	if (!ft_create_list(root, &start, &length, &t))
		return ;
	length >>= 1;
	t = start;
	max_nbr_width = ft_digitsnbr(*(int*)start->content);
	while ((t = t->next))
		if (max_nbr_width < (width = ft_digitsnbr(*(int*)t->content)))
			max_nbr_width = width;
	ft_print_tree(start, length, length, max_nbr_width);
	ft_lstdel(&start, ft_del);
}
