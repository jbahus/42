/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:55:24 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/01 20:55:28 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stock	*ft_create_lst(int nb, t_stock *lst)
{
	t_stock *new_lst;

	new_lst = (t_stock*)malloc(sizeof(t_stock));
	new_lst->nb = nb;
	new_lst->prev = lst;
	lst->next = new_lst;
	return (new_lst);
}

t_stock *ft_return_bol(t_stock *lst)
{
	while (lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}

t_stock	*ft_go_lst(char *line, t_stock *lst)
{
	char		**ret;

	ret = (char**)ft_strnew(ft_strlen(line));
	ret = ft_strsplit(line, ' ');
	lst->nb = ft_atoi(*ret);
	ret++;
	while (*ret != NULL)
	{
		lst = ft_create_lst(ft_atoi(*ret), lst);
		ret++;
	}
	return (lst);
}

int		open_f(char *fname)
{
	int		fd;
	char	*line;
	t_stock *lst;

	fd = open(fname, O_RDONLY);
	if (!fd)
		return (0);
	line = NULL;
	lst = (t_stock*)malloc(sizeof(t_stock));
	lst->prev = NULL;
	while (get_next_line(fd, &line))
	{
		ft_go_lst(line, lst);
		lst = ft_create_lst('\n', lst);
		free(line);
	}
	ft_return_bol(lst);
	close(fd);
	return (0);
}
