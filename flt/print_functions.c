/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:29:51 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/03/03 18:47:47 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

int		print_usage(void)
{
	ft_putendl("usage: ./fillit map_file");
	return (-1);
}

int		clear_print_and_return(int res, t_x *root, unsigned char ***mx)
{
	free_mx(mx);
	reconnect_secondary_columns(root);
	clear_structure(&root);
	if (!res)
		ft_putendl("error");
	return (res ? 1 : -1);
}

unsigned char	get_figure_name_by_point(t_list *solution, unsigned char *point)
{
	t_x		*r;
	t_list	*t;

	t = solution;
	while (t)
	{
		r = (t_x*)t->content;
		while ((r = r->r) != (t_x*)t->content)
			if (r->c->n[0] + '0' == point[0] && r->c->n[1] + '0' == point[1])
				return (((t_x*)t->content)->c->n[0]);
		t = t->next;
	}
	return ('.');
}

int		get_map_size_solution(t_list *solution)
{
	int		map_size;
	int		max;
	t_x		*r;
	t_x		*x;

	map_size = 0;
	while (solution)
	{
		r = (t_x*)solution->content;
		x = r;
		while ((x = x->r) != r)
		{
			max = x->c->n[0]  > x->c->n[1] ? x->c->n[0] : x->c->n[1];
			map_size = map_size < max ? max : map_size;
		}
		solution = solution->next;
	}
	return (map_size);
}

int		print_solution(t_list *solution)
{
	unsigned char	point[3];
	int		map_size;

	point[0] = '1';
	point[1] = '1';
	point[2] = 0;
	map_size = get_map_size_solution(solution);
	while (point[0] - '0' <= map_size)
	{
		while (point[1] - '0' <= map_size)
		{
			ft_putchar(get_figure_name_by_point(solution, point));
			point[1]++;
		}
		ft_putchar('\n');
		point[1] = '1';
		point[0]++;
	}
	return (1);
}
