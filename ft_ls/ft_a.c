/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:50:25 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/09 15:16:43 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_a(char *dirname)
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
		tls->f_name = files->d_name;
		tls = new_tls(tls);
	}
	tls = tls->next;
	aff_ls(tls, 0);
	closedir(dir);
}