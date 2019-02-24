/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmors-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:08:19 by tmors-ma          #+#    #+#             */
/*   Updated: 2018/12/22 18:08:20 by tmors-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strrealloc(const char *str, char **line)
{
	char	*temp;

	temp = NULL;
	if (*line)
		temp = *line;
	*line = temp ? ft_strnew(ft_strlen(str) + ft_strlen(temp))
		: ft_strnew(ft_strlen(str));
	if (!*line)
	{
		if (temp)
			free(temp);
		return (NULL);
	}
	if (temp)
		ft_strcpy(*line, temp);
	ft_strcat(*line, str);
	if (temp)
		free(temp);
	return (line);
}
