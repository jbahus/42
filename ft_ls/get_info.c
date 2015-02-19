/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:06:34 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/19 20:08:30 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swp_alph_order(t_tls **tmp, t_tls **next)
{
	char	*str;

	if (ft_strcmp((*tmp)->f_name, (*next)->f_name) > 0)
		{
			str = (*next)->f_name;
			(*next)->f_name = (*tmp)->f_name;
			(*tmp)->f_name = str;
		}
}

void	alph_order(t_tls *tls, int r)
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
				swp_alph_order(&tmp, &next);
			else
				rev_order(&tmp, &next);
			next = next->next;
		}
		tmp = tmp->next;
	}
}

t_tls	*new_tls(t_tls *tls)
{
	t_tls	*new_t;

	new_t = malloc(sizeof(*tls));
	new_t->next = tls;
	return (new_t);
}

t_tls	*get_name(char *dirname, t_opt opt)
{
	DIR		*dir;
	t_dir	*files;
	t_tls	*tls;

	if (dirname == NULL)
	{
		if (!(dir = opendir("./")))
			ft_error("./");
	}
	else if (!(dir = opendir(dirname)))
		ft_error(dirname);
	tls = malloc(sizeof(*tls));
	tls->next = NULL;
	while ((files = readdir(dir)))
	{
		tls = new_tls(tls);
		tls->f_name = files->d_name;
	}
	if (opt.r == 1)
		alph_order(tls, 1);
	else
		alph_order(tls, 0);
	closedir(dir);
	return (tls);
}