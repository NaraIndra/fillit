/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_bst_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:35:40 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/12 18:35:41 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_add_item(t_avl *node, t_list **start)
{
	t_list	*new;
	char	bf[15];
	char	*temp;
	int		i;
	int		j;

	if (!(temp = node ? ft_itoa(node->key) : ft_itoa(0)))
		return (NULL);
	i = 0;
	while ((bf[i] = temp[i]))
		i++;
	free(temp);
	bf[i++] = '(';
	if (!(temp = node ? ft_itoa(ft_tree_avl_getbalance(node)) : ft_itoa(0)))
		return (NULL);
	j = 0;
	while ((bf[i++] = temp[j++]))
		;
	bf[--i] = ')';
	bf[++i] = '\0';
	free(temp);
	if (!(new = ft_lstnew(node ? bf : ft_memalloc(4), node ? sizeof(bf) : 4)))
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

static int			ft_create_list(t_avl *r, t_list **s, int *l, t_list **last)
{
	t_list			*temp;
	t_bst			*node;
	char			**t;

	temp = *last ? (*last)->next : *s;
	*last = temp;
	t = temp ? ft_strsplit((char*)temp->content, '(') : NULL;
	if (t && *t)
	{
		node = ft_tree_search((void*)r, ft_atoi(*t));
		ft_freearray((void**)t, 2);
	}
	else
		node = NULL;
	if (!ft_add_item(node ? (t_avl*)node->left : NULL, s) ||
		!ft_add_item(node ? (t_avl*)node->right : NULL, s))
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

	i = 1;
	base_width = (l - (l >> 1)) * n_w * 2 - 1;
	while ((i = l & i))
	{
		ft_putcharn(' ', (io >> 1) * n_w);
		c = i;
		while (c--)
		{
			if (*(int*)s->content == 0)
				ft_putstrw("0", n_w, ' ');
			else
				ft_putstrw(s->content, n_w, ' ');
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

void				ft_tree_avl_print(t_avl *root)
{
	t_list	*start;
	t_list	*t;
	int		length;
	size_t	max_nbr_width;
	size_t	width;

	if (!root)
		return ;
	length = 1;
	start = NULL;
	if (!(start = ft_add_item(root, &start)))
		return ;
	t = NULL;
	if (!ft_create_list(root, &start, &length, &t))
		return ;
	length >>= 1;
	t = start;
	max_nbr_width = ft_strlen((char*)start->content);
	while ((t = t->next))
		if (max_nbr_width < (width = ft_strlen((char*)t->content)))
			max_nbr_width = width;
	ft_print_tree(start, length, length, max_nbr_width);
	ft_lstdel(&start, ft_del);
}
