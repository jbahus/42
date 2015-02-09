/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:04:08 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/09 15:16:18 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rev_order(t_tls **tmp, t_tls **next)
{
	char	*str;

	if (ft_strcmp((*tmp)->f_name, (*next)->f_name) < 0)
		{
			str = (*next)->f_name;
			(*next)->f_name = (*tmp)->f_name;
			(*tmp)->f_name = str;
		}
}

void	ft_r(char *dirname)
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
	aff_ls(tls, 1);
	closedir(dir);
}