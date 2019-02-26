/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xalg.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:37:42 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/27 01:42:49 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XALG_H
# define XALG_H
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_x
{
	struct s_x	*l;
	struct s_x	*r;
	struct s_x	*dl;
	struct s_x	*dr;
	struct s_x	*u;
	struct s_x	*d;
	struct s_x	*c;
	char		p;
	char		n[5];
}				t_x;

/*
** tx_functions.c
*/
t_x				*new_tx(const char *name);
t_x				*insert_right_tx(t_x *root, t_x *new);
t_x				*insert_left_tx(t_x *root, t_x *new);
t_x				*insert_up_tx(t_x *root, t_x *new);
t_x				*insert_down_tx(t_x *root, t_x *new);
/*
** cover_functions.c
*/
void			cover_column(t_x *c);
void			uncover_column(t_x *c);
void			cover_inner_columns(t_x *r);
void			uncover_inner_columns(t_x *r);
/*
** utility_functions.c
*/
t_x				*find_column_object_by_name(t_x *root, const char *name);
int				in_arr(t_x *e, t_x *arr[], int *size);
int				is_connected(char *src);
int				is_valid(char *str);
void			clear_structure(t_x **root);
/*
** print_functions.c
*/
int				clear_print_and_return(int res, t_x *root);
int				print_usage(void);
char			get_figure_name_by_point(t_list *solution, char *point);
int				get_map_size_solution(t_list *solution);
int				print_solution(t_list *solution);
/*
** print_utility_functions.c
*/
void			print_row(t_x *row);
void			print_column_objects(t_x *root);
void			print_structure(t_x *root);
void			print_structure_columns(int *i, int *a, t_x *dn, t_x *arr[]);
int				print_solution_as_structure(t_list *solution);
/*
** connection_functions.c
*/
void			disconnect_secondary_columns(t_x *root);
void			reconnect_secondary_columns(t_x *root);
/*
** get_figure_functions.c
*/
void			prepare_line(char *dst, char *src, int shift_margin, int map_size);
int				get_shift_margin(char *str);
int				get_figure(int fd, char *line, int prev_length, int map_size);
int				process_file(char *file_name, t_x *root, const char ***cols, int map_size);
/*
** create_matrix_functions.c
*/
t_x				*create_root(void);
int				create_column_objects(t_x *root, const char ***cols);
t_x				*append_figure_type_column(t_x *root, char *figure);
int				insert_figure(t_x *root, t_x *row, char *line, const char ***cols);
int				create_matrix_row(t_x *root, char *figure, char *line, const char ***cols);
/*
** enlarge_map_functions.c
*/
int				get_map_size_structure(t_x *root);
void			adjust_matrix(t_x *root, int map_size);
int				enlarge_map(t_x *root, int map_size);
int				add_row(t_x *root, int map_size);
int				add_columns(t_x *root, int map_size);
/*
** extrapolate_functions.c
*/
int				matrix_extrapolate(t_x *root, int map_size, int init);
int				matrix_extrapolate_down_one(t_x *co);
int				matrix_extrapolate_down_all(t_x *co, int map_size);
int				matrix_extrapolate_right_one(t_x *co);
int				matrix_extrapolate_right_all(t_x *row, int map_size);
/*
** extrapolate_utility_functions.c
*/
int				copy_down(t_x *row, t_x *new_row, int xc);
int				copy_right(t_x *row, t_x *new_row, int xc);
int				matrix_insert_right_one(t_x *most_right);
/*
** main.c
*/
t_list			*add_solution(t_x *r, t_list **solution);
void			remove_last_solution(t_list **solution);
int				xalg(t_x *root, t_list **solution);

#endif
