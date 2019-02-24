/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:31:03 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/10 00:31:04 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

t_list	*add_solution(t_x *r, t_list **solution)
{
	t_list *t;

	t = (t_list*)malloc(sizeof(*t));
	if (!t)
		return (NULL);
	t->next = NULL;
	t->content = r;
	t->content_size = sizeof(r);
	if (!*solution)
		*solution = t;
	else
		ft_lstappend(*solution, t);
	return (t);
}

void	remove_last_solution(t_list **solution)
{
	t_list *t;
	t_list *b;

	t = *solution;
	b = t->next;
	while (t->next)
	{
		b = t;
		t = t->next;
	}
	free(t);
	if (b)
		b->next = NULL;
	else
		*solution = NULL;
}

int		xalg(t_x *root, t_list **solution)
{
	t_x *c;
	t_x *r;
	int res;

	res = 0;
	if ((c = root->r) == root)
		return (print_solution(*solution));
	cover_column(c);
	r = c;
	while ((r = r->d) != c && !res)
	{
		if (!add_solution(r, solution))
		{
			uncover_column(c);
			return (-1);
		}
		cover_inner_columns(r);
		res = xalg(root, solution);
		remove_last_solution(solution);
		uncover_inner_columns(r);
	}
	uncover_column(c);
	return (res);
}

int		main(int argc, char **argv)
{
	t_x		*root;
	t_list	*solution;
	int		res;
	int		map_size;

	if (argc != 2)
		return (print_usage());
	solution = NULL;
	if (!(root = create_root()) || !create_column_objects(root)
		|| process_file(argv[1], root) < 0)
		return (clear_print_and_return(0, root));
	adjust_matrix(root, (map_size = get_map_size_structure(root)));
	if (!matrix_extrapolate(root, map_size, 1))
		return (clear_print_and_return(0, root));
	disconnect_secondary_columns(root);
	while (!(res = xalg(root, &solution)))
		if (!enlarge_map(root, ++map_size))
			return (clear_print_and_return(0, root));
	return (clear_print_and_return(res < 0 ? 0 : 1, root));
}
