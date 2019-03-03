/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figure_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:30:04 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/03/03 16:33:20 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"

/*
** prepare_line: removes new lines, substitutes for ones and zeroes,
** shifts to the left, skips empty rows
*/

void		prepare_line(unsigned char *dst, unsigned char *src, int sh_m, int map_size)
{
	int		n;
	int		count;
	int		cn;

	n = 0;
	count = map_size;
	cn = sh_m;
	cut_src(&src);
	while (*src++ && !(n == 4))
	{
		if (*(src - 1) == '#' && ++n && count--)
			*dst++ = '1';
		else if (*(src - 1) == '\n')
		{
			while (count--)
				*dst++ = '0';
			count = map_size;
			cn = sh_m;
		}
		else if (*(src - 1) == '.' && !cn && count--)
			*dst++ = '0';
		else
			--cn;
	}
}

int			get_sh_m(unsigned char *str)
{
	int		i;
	int		new_line;
	int		sh_m;
	int		length;

	length = 20;
	new_line = 1;
	sh_m = 5;
	i = 0;
	while (length-- && sh_m != 0)
	{
		if (*str == '.' && new_line)
			i++;
		else if (*str == '\n')
		{
			sh_m = sh_m > i ? i : sh_m;
			new_line = 1;
			i = 0;
		}
		else if (new_line)
			new_line = 0;
		str++;
	}
	return (sh_m);
}

/*
** get_figure: last read returns 0 and according to the task
** last tetramino must be 20 length, others are 21 (contain 2\n)
*/

int			get_figure(int fd, unsigned char *line, int prev_length, int map_size)
{
	int		ret;
	unsigned char	buf[22];

	ft_bzero(buf, 22);
	ft_bzero(line, map_size * map_size + 1);
	ret = read(fd, buf, 21);
	if (!ret)
		return (prev_length == 21 || prev_length == 0 ? -1 : 0);
	if (!is_valid(buf))
		return (-1);
	prepare_line(line, buf, get_sh_m(buf), map_size);
	return (ft_ustrlen(buf));
}

int			process_file(char *file_name, t_x *root,  unsigned char ***cols, int map_size)
{
	int				fd;
	unsigned char	figure[2];
	int				res;
	unsigned char	line[map_size * map_size + 1];

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	res = 0;
	figure[0] = 'A';
	figure[1] = 0;
	while ((res = get_figure(fd, line, res, map_size)) > 0)
	{
		if (!create_matrix_row(root, figure, line, cols))
			return (-1);
		figure[0]++;
	}
	return (res);
}
