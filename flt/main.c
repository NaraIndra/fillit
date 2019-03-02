/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 00:44:27 by mstygg            #+#    #+#             */
/*   Updated: 2019/03/02 17:57:02 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

t_list				*add_solution(t_x *r, t_list **solution)
{
	t_list			*t;

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

void				remove_last_solution(t_list **solution)
{
	t_list			*t;
	t_list			*b;

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

int					xalg(t_x *root, t_list **solution)
{
	t_x				*c;
	t_x				*r;
	int				res;

	res = 0;
	if ((c = root->r) == root)
		return (print_solution(*solution));
	cover_column(c->c);
	r = c;
	while ((r = r->d) != c && !res)
	{
		if (!add_solution(r, solution))
		{
			uncover_column(c->c);
			return (-1);
		}
		cover_inner_columns(r);
		res = xalg(root, solution);
		c = r->c;
		remove_last_solution(solution);
		uncover_inner_columns(r);
	}
	uncover_column(c->c);
	return (res);
}

int					main(int argc, char **argv)
{
	t_x				*root;
	t_list			*solution;
	int				res;
	static char		**c_s;
	int				count;

	if (argc != 2)
		return (print_usage());
	solution = NULL;
	count = f_s(4 * c_f(argv[1])) < 4 ? (4) : f_s(4 * c_f(argv[1]));
	printf("count=%d\n", count);
	if (!(fill_mx(create_ch(&c_s, count), count)))
		return (-1);
		int k = 0;
	while(*(c_s + k))
	{
		printf("%s\n",*(c_s + k++));
	}
	if (!(root = create_root()) || !(create_column_objects(root, &c_s))
		|| (process_file(argv[1], root, &c_s, count) < 0))
		return (clear_print_and_return(0, root, &c_s));
	printf("process_ok\n");
	print_structure(root);
	if (count == 4)
		adjust_matrix(root, (count = get_m_s_structure(root)));
	if (!matrix_extrapolate(root, count, 1))
		return (clear_print_and_return(0, root, &c_s));
	printf("extrapolate_ok\n");
//	print_structure(root);
//	getchar();
	disconnect_secondary_columns(root);
	while (!(res = xalg(root, &solution)))
		if (!enlarge_map(root, ++count))
			return (clear_print_and_return(0, root, &c_s));
	return (clear_print_and_return(res < 0 ? (0) : (1), root, &c_s));
}
