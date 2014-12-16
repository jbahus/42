/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:55:24 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/16 21:09:16 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_create_tab(int *tab, char *line)
{
	char	**ret;
	int 	size;
	int 	i;

	i = 0;
	size = 0;
	ret = ft_strsplit(line, ' ');
	if (!ret)
		return (NULL);
	while (ret[size])
		size++;
	tab = (int*)malloc(sizeof(int) * (size + 1));
	if (!tab)
		return (NULL);
	tab[i++] = size;
	while (ret[i])
	{
		tab[i] = ft_atoi(ret[i]);
		i++;
	}
	free(ret);
	return (tab);
}

int		**ft_split(char *tmp)
{
	char	**ret;
	int 	size;
	int 	**tab;
	int 	i;

	i = 0;
	size = 0;
	ret = ft_strsplit(tmp, '\n');
	if (!ret)
		return (NULL);
	while (ret[size])
		size++;
	tab = (int**)malloc(sizeof(int*) * (size + 1));
	if (!tab)
		return (NULL);
	tab[0] = (int*)malloc(sizeof(int));
	tab[0][0] = size;
	while (ret[i])
	{
		tab[i + 1] = ft_create_tab(tab[i + 1], ret[i]);
		i++;
	}
	free(ret);
	return (tab);
}

int		**open_f(t_env *e)
{
	char	*tmp;
	int		fd;
	char	*line;
	int 	ret;
	int 	**tab;

	fd = open(e->fname, O_RDONLY);
	if (fd < 0)
		ft_error(e->fname);
	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		tmp = ft_strjoin(tmp, line);
		tmp = ft_strjoin(tmp, "\n");
		free(line);
	}
	close(fd);
	if (ret == -1)
		ft_error(e->fname);
	tab = ft_split(tmp);
	ft_strdel(&tmp);
	return (tab);
}
