/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xalg.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:37:42 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/03/02 23:27:36 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XALG_H
# define XALG_H
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# define EPS 1e-5

typedef struct			s_x
{
	struct s_x			*l;
	struct s_x			*r;
	struct s_x			*dl;
	struct s_x			*dr;
	struct s_x			*u;
	struct s_x			*d;
	struct s_x			*c;
	unsigned char		p;
	unsigned char		n[2];
}						t_x;

/*
** tx_functions.c
*/
t_x				*new_tx(const unsigned char *name);
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
t_x				*find_column_object_by_name(t_x *root,  unsigned char *name);
int				in_arr(t_x *e, t_x *arr[], int *size);
int				is_connected(unsigned char *src);
int				is_valid(unsigned char *str);
void			clear_structure(t_x **root);
double			ft_abs(double n);
int				f_s(int nb);
/*
** print_functions.c
*/
int				clear_print_and_return(int res, t_x *root, unsigned char ***mx);
int				print_usage(void);
unsigned char			get_figure_name_by_point(t_list *solution, unsigned char *point);
int				get_m_s_solution(t_list *solution);
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
void			prepare_line(unsigned char *dst, unsigned char *src, int shift_margin, int m_s);
int				get_shift_margin(unsigned char *str);
int				get_figure(int fd, unsigned char *line, int prev_length, int m_s);
int				process_file(char *file_name, t_x *root, unsigned char ***cols, int m_s);
/*
** create_matrix_functions.c
*/
t_x				*create_root(void);
int				create_column_objects(t_x *root, unsigned char ***cols);
t_x				*append_figure_type_column(t_x *root, unsigned char *figure);
int				insert_figure(t_x *root, t_x *row, unsigned char *line, unsigned char ***cols);
int				create_matrix_row(t_x *root, unsigned char *fig, unsigned char *line, unsigned char ***cs);
/*
** enlarge_map_functions.c
*/
int				get_m_s_structure(t_x *root);
void			adjust_matrix(t_x *root, int m_s);
int				enlarge_map(t_x *root, int m_s);
int				add_row(t_x *root, int m_s);
int				add_columns(t_x *root, int m_s);
/*
** extrapolate_functions.c
*/
int				matrix_extrapolate(t_x *root, int m_s, int init);
int				matrix_extrapolate_down_one(t_x *co);
int				matrix_extrapolate_down_all(t_x *co, int m_s);
int				matrix_extrapolate_right_one(t_x *co);
int				matrix_extrapolate_right_all(t_x *row, int m_s);
/*
** extrapolate_utility_functions.c
*/
int				copy_down(t_x *row, t_x *new_row, int xc);
int				copy_right(t_x *row, t_x *new_row, int xc);
int				matrix_insert_right_one(t_x *most_right);
/*
** almost_useless_func.c
*/
void			cut_src(unsigned char **src);
int				c_f(char *filename);
int				fill_mx(unsigned char ***ar, int num);
unsigned char	***create_ch(unsigned char ***new, int num);
unsigned char	**free_mx(unsigned char ***arr);
/*
** sq_root_func.c  (root and unsigned strlen)
*/
double			ft_abs(double n);
int				f_s(int nb);
int				ft_ustrlen(const unsigned char *str);
/*
** main.c
*/
t_list			*add_solution(t_x *r, t_list **solution);
void			remove_last_solution(t_list **solution);
int				xalg(t_x *root, t_list **solution);

#endif
