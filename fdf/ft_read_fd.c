/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:55:24 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/06 19:25:01 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stock	*ft_create_lst(int nb, char nl, t_stock *lst)
{
	t_stock *new_lst;

	if (!lst)
	{
		lst = (t_stock*)malloc(sizeof(t_stock));
		lst->prev = NULL;
		lst->nl = nl;
		lst->nb = nb;
		return (lst);
	}
	else
	{
		new_lst = (t_stock*)malloc(sizeof(t_stock));
		new_lst->nb = nb;
		new_lst->nl = nl;
		new_lst->prev = lst;
		new_lst->next = NULL;
		lst->next = new_lst;
	}
	return (new_lst);
}

t_stock *ft_return_bol(t_stock *lst)
{
	while (lst->prev != NULL)
		lst = lst->prev;
	//lst = lst->next;
	return (lst);
}

t_stock	*ft_go_lst(char *line, t_stock *lst)
{
	char		**ret;

	ret = ft_strsplit(line, ' ');
	while (*ret)
	{
		lst = ft_create_lst(ft_atoi(*ret), '\0', lst);
		free(*ret);
		ret++;
	}
	return (lst);
}

t_stock	*open_f(t_env *e)
{
	char	*line;
	int		ret;
	int 	fd;
	t_stock *lst;

	fd = open(e->fname, O_RDONLY);
	if (fd < 0)
		ft_error(e->fname);
	line = NULL;
	lst = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			ft_error(e->fname);
		lst = ft_go_lst(line, lst);
		lst = ft_create_lst('\0', '\n', lst);
		free(line);
	}
	lst = ft_return_bol(lst);
	close(fd);
	return (lst);
}
