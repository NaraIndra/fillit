/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 00:29:06 by tmors-ma          #+#    #+#             */
/*   Updated: 2019/01/25 00:29:07 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_avl	*get_repo(const int fd, t_avl **repo_root)
{
	t_avl	*temp;

	if (!*repo_root)
		if (!(*repo_root = ft_tree_avl_new(fd, NULL, 0)))
			return (NULL);
	if (!ft_tree_search(*repo_root, fd))
	{
		if (!(temp = ft_tree_avl_new(fd, NULL, 0)))
			return (NULL);
		*repo_root = ft_tree_avl_insert(*repo_root, temp);
	}
	return (ft_tree_search(*repo_root, fd));
}

static void		update_repo(const int fd, t_avl *repo, char *str)
{
	t_avl	*current;

	current = ft_tree_search(repo, fd);
	free(current->content);
	current->content = str;
	current->content_size = str ? ft_strlen(str) : 0;
}

static int		manage_line(char *str, char **line, const int fd, t_avl *repo)
{
	char	*npos;
	char	*temp;

	if (!str)
		return (-1);
	if ((npos = ft_strchr(str, '\n')))
		*npos = '\0';
	if (!(*line = ft_strdup(str)))
	{
		ft_strdel(&str);
		return (-1);
	}
	if (npos && ft_strlen(npos + 1))
	{
		if (!(temp = ft_strdup(npos + 1)))
		{
			ft_strdel(&str);
			return (-1);
		}
	}
	else
		temp = NULL;
	update_repo(fd, repo, temp);
	ft_strdel(&str);
	return (1);
}

static int		read_input(const int fd, char **read_buf)
{
	char	buf[GNL_BUFF_SIZE + 1];
	char	*t;
	int		ret;
	int		mult;

	mult = 1;
	ret = -1;
	if (!(*read_buf = ft_strnew(GNL_BUFF_SIZE * mult)))
		return (-1);
	while (ret && (ret == -1 || !ft_strchr(buf, '\n')))
	{
		if ((ret = read(fd, buf, GNL_BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret > (int)(GNL_BUFF_SIZE * mult - ft_strlen(*read_buf)))
		{
			t = *read_buf;
			if (!(*read_buf = ft_strnew(GNL_BUFF_SIZE * (mult *= 2))))
				return (-1);
			ft_strcpy(*read_buf, t);
			ft_strdel(&t);
		}
		ft_strcat(*read_buf, buf);
	}
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_avl	*repo_root;
	t_avl			*repo;
	char			*read;
	char			*str;

	if (fd < 0 || !line || !(repo = get_repo(fd, &repo_root)))
		return (-1);
	if (repo->content && ft_strchr(repo->content, '\n'))
		return (manage_line(ft_strdup(repo->content), line, fd, repo_root));
	if (read_input(fd, &read) == -1)
	{
		ft_strdel(&read);
		return (-1);
	}
	if (!ft_strlen(read) && !repo->content)
	{
		repo_root = ft_tree_avl_delone(repo_root, fd);
		ft_strdel(&read);
		return (0);
	}
	str = repo->content ? ft_strjoin(repo->content, read) : read;
	if (repo->content)
		ft_strdel(&read);
	return (str ? manage_line(str, line, fd, repo_root) : -1);
}
