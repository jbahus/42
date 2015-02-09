/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:38:04 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/09 18:46:01 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_write_t(t_tls *tls)
{
	while (tls->next)
	{
		ft_putendl(tls->f_name);
		tls = tls->next;
	}
}

void	t_order(t_tls **tmp, t_tls **next)
{
	char	*str;
	int		a;

	if (ft_strcmp((*tmp)->f_name, (*next)->f_name) > 0)
	{
		str = (*next)->f_name;
		a = (*next)->mtime;
		(*next)->mtime = (*tmp)->mtime;
		(*next)->f_name = (*tmp)->f_name;
		(*tmp)->f_name = str;
		(*tmp)->mtime = a;
	}
}

void	trie_t(t_tls **tls)
{
	t_tls	*tmp;
	t_tls	*next;
	char	*str;
	int		a;

	tmp = *tls;
	while (tmp->next)
	{
		next = tmp->next;
		while (next->next)
		{
			if (tmp->mtime < next->mtime)
			{
				str = next->f_name;
				a = next->mtime;
				next->mtime = tmp->mtime;
				next->f_name = tmp->f_name;
				tmp->f_name = str;
				tmp->mtime = a;
			}
			else if (tmp->mtime == next->mtime)
				t_order(&tmp, &next);
			next = next->next;
		}
		tmp = tmp->next;
		next = tmp->next;
	}
}

t_tls	*stock_t(char *f_name, int mtime, t_tls *tls)
{
	t_tls	*new_t;

	new_t = malloc(sizeof(*tls));
	new_t->f_name = f_name;
	new_t->mtime = mtime;
	new_t->next = tls;
	return (new_t);
}

void	ft_t(const char *dirname)
{
	t_stat	*st;
	DIR		*dir;
	t_dir	*files;
	t_tls	*tls;

	if (!(dir = opendir(dirname)))
		ft_error(dirname);
	st = malloc(sizeof(*st));
	tls = malloc(sizeof(*tls));
	tls->next = NULL;
	while ((files = readdir(dir)))
	{
		if (files->d_name[0] != '.')
		{
			stat(files->d_name, st);
			tls = stock_t(files->d_name, st->st_mtime, tls);
		}	
	}
	trie_t(&tls);
	ft_write_t(tls);
	closedir(dir);
}