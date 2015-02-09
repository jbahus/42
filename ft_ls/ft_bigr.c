/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:00:36 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/09 18:45:59 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	stock_R(char *f_name, int isdir, t_tls *tls)
{
	t_tls	*new_tls;

	new_tls = malloc(sizeof(tls*));
	new_tls->next = tls;
	new_tls->isdir = isdir;
	new_tls->f_name = f_name;
	return (new_tls);
}

void	ft_R(const char *dirname)
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
		stat(files->d_name, st);
		tls = stock_R(files->d_name, S_ISDIR(st->st_mode), tls);
	}
	alph_order_R(&tls, &tls->next);
	while (tls->next)
	{
		if (tls->f_name[0] == '.')

	}
	ft_write_t(tls);
	closedir(dir);
}