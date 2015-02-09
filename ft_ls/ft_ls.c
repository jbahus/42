/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:31:00 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/09 18:46:02 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	alph_order(t_tls **tmp, t_tls **next)
{
	char	*str;

	if (ft_strcmp((*tmp)->f_name, (*next)->f_name) > 0)
		{
			str = (*next)->f_name;
			(*next)->f_name = (*tmp)->f_name;
			(*tmp)->f_name = str;
		}
}

void	aff_ls(t_tls *tls, int r)
{
	t_tls *tmp;
	t_tls *next;

	tmp = tls;
	while (tmp)
	{
		next = tmp->next;
		while (next)
		{
			if (r == 0)
				alph_order(&tmp, &next);
			else
				rev_order(&tmp, &next);
			next = next->next;
		}
		tmp = tmp->next;
	}
	while (tls)
	{
		ft_putendl(tls->f_name);
		tls = tls->next;
	}
}

t_tls	*new_tls(t_tls *tls)
{
	t_tls	*new_t;

	new_t = malloc(sizeof(*tls));
	new_t->next = tls;
	return (new_t);
}

void	ft_ls(char *dirname)
{
	DIR		*dir;
	t_dir	*files;
	t_tls	*tls;

	if (!(dir = opendir(dirname)))
		ft_error(dirname);
	tls = malloc(sizeof(*tls));
	tls->next = NULL;
	while ((files = readdir(dir)))
	{
		if (files->d_name[0] != '.')
			{
				tls->f_name = files->d_name;
				tls = new_tls(tls);
			}
	}
	tls = tls->next;
	aff_ls(tls, 0);
	closedir(dir);
}