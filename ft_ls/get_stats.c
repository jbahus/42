/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:06:47 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/19 20:08:46 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_tls	*get_time(t_tls *tls)
{
	t_stat	*st;
	t_tls	*tmp;

	tmp = tls;
	st = malloc(sizeof(*st));
	while (tmp->next)
	{
		stat(tmp->f_name, st);
		tmp->mtime = st->st_mtime;
		tmp = tmp->next;
	}
	trie_t(&tls);
	return (tls);
}

t_tls	*get_isdir(t_tls *tls)
{
	t_stat	*st;
	t_tls	*tmp;

	tmp = tls;
	st = malloc(sizeof(*st));
	while (tmp->next)
	{
		stat(tmp->f_name, st);
		tmp->isdir = S_ISDIR(st->st_mode);
		tmp = tmp->next;
	}
	return (tls);
}

t_tls	*get_stats(t_tls *tls, t_opt opt)
{
	if (opt.t == 1)
		tls = get_time(tls);
	if (opt.R == 1)
		tls = get_isdir(tls);
	return (tls);
}