
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figure_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:30:04 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/02/27 01:05:51 by mstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xalg.h"
#define epsilon 1e-5

/*
** prepare_line: removes new lines, substitutes for ones and zeroes,
** shifts to the left, skips empty rows
*/

static void cut_src(char **src)
{
	int		i;

	i = 0;
	while (*((*src) + i) == '.' || *((*src) + i) == '\n')
		++i;
	while ((i -=5) >= 0)
		(*src) += 5;
}

void	prepare_line(char *dst, char *src, int shift_margin, int map_size)
{
	int		n;
	int		count;
    int		cn;

	n = 0;
	count = map_size;
    cn = shift_margin;
	cut_src(&src);
	while (*src++)
	{
		if (n == 4)
            return ;
		if (*(src - 1) == '#' && ++n && count--)
            *dst++ = '1';
		else if (*(src - 1) == '\n')
		{
			while(count--)
                *dst++ = '0';
			count = map_size;
            cn = shift_margin;
		}
		else if (*(src - 1) == '.' && !cn && count--)
            *dst++ = '0';
        else    
            --cn;
	}
}

int		get_shift_margin(char *str)
{
	int i;
	int	new_line;
	int shift_margin;
	int length;

	length = 20;
	new_line = 1;
	shift_margin = 5;
	i = 0;
	while (length-- && shift_margin != 0)
	{
		if (*str == '.' && new_line)
			i++;
		else if (*str == '\n')
		{
			shift_margin = shift_margin > i ? i : shift_margin;
			new_line = 1;
			i = 0;
		}
		else if (new_line)
			new_line = 0;
		str++;
	}
	return (shift_margin);
}

/*
** get_figure: last read returns 0 and according to the task
** last tetramino must be 20 length, others are 21 (contain 2\n)
*/

int		get_figure(int fd, char *line, int prev_length, int map_size)
{
	int		ret;
	char	buf[22];
	ft_bzero(buf, 22);
	ft_bzero(line, map_size * map_size + 1);
	ret = read(fd, buf, 21);
	if (!ret)
		return (prev_length == 21 || prev_length == 0 ? -1 : 0);
	if (!is_valid(buf))
		return (-1);
	prepare_line(line, buf, get_shift_margin(buf), map_size);
	return (ft_strlen(buf));
}

int		process_file(char *file_name, t_x *root, const char ***cols, int map_size)
{
	int		fd;
	char	figure[2];
	int		res;
	char	line[map_size * map_size + 1];
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