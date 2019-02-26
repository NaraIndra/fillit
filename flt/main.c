
#include "xalg.h"
#define epsilon 1e-5

//static char		*cols[17] = {"11", "12", "13", "14", "21", "22", "23",\
//	"24", "31", "32", "33", "34", "41", "42", "43", "44", 0};
double		ft_abs(double n)
{
	return (n >= 0) ? (n) : (-n);
}

int			f_s(int nb)
{
	double	x_n;
	double	b;
	double	x_n_1;

	if (nb >= 0)
	{
		x_n = 1;
		b = nb;
		x_n_1 = nb;
		while (ft_abs(x_n_1 - x_n) > epsilon)
		{
			x_n = (x_n + b) / 2;
			b = nb / x_n;
			x_n_1 = (x_n + b) / 2;
		}
		return(x_n_1);
	}
	return (-1);
}

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

static char *** create_ch(char ***new, int num)
{
	char	**tmp;
	int count;

	count = (num * num);
	if (!(*new = (char**)malloc((count + 1) * sizeof(char*))))
		return (NULL);
	tmp = *new;
	while (count--)
	{
		if (!(*(*new)++ = (char*)malloc(3 * sizeof(char))))
			return (NULL);
	}
	*(*new) = NULL;
	*new = tmp;
	return (new);
}

static int fill_mx(char ***ar, int num)
{
	int 	i;
	int		j;
	char	first;
	char	sec;
	int		count;

	i = 0;
	j = 1;
	first = '1';
	sec = '1';
	count = num * num;
	if (!(*ar))
		return (0);
	while(*((*ar) + i))
	{
			*(*((*ar) + i) + 0) = first;
			*(*((*ar) + i) + 1) = sec++;
			if (sec == (num + 1) + '0')
			{
				sec = '1';
				first++;
			}
			++i;
	}
	return (1);
}

static int	c_f(char *filename)
{
	int fd;
	int ret;
	char buf[22];
	int count;

	count = 0;
	if (!(fd = open(filename, O_RDONLY)))
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		++count;
	}
	close(fd);
	return (count);
}

int		main(int argc, char **argv)
{
	t_x			*root;
	t_list		*solution;
	int			res;
	static char	**c_s;
	const char	**tt;
	int			count;

	if (argc != 2)
		return (print_usage());
	solution = NULL;
	count = f_s(4 * c_f(argv[1])) < 4 ? (4) : f_s(4 * c_f(argv[1]));
	if (!(fill_mx(create_ch(&c_s, count), count)))
		return (-1);
	tt = (const char**)c_s;
	if (!(root = create_root()) || !(create_column_objects(root, &tt)) 
		|| (process_file(argv[1], root, &tt, count) < 0))
		return (-1);
	//print_structure(root);
	//adjust_matrix(root, count);
	if (!matrix_extrapolate(root, count, 1))
		return (-1);
//	print_structure(root);
	disconnect_secondary_columns(root);
	while (!(res = xalg(root, &solution)))
	{
		if (!enlarge_map(root, ++count))
			return (-1);
	}
	reconnect_secondary_columns(root);
	clear_structure(&root);
	return (res > 0) ? (1) : (-1);
}
