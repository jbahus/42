/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:31:00 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/27 19:13:17 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *dirname)
{
	DIR		*dir;
	t_dir	*files;

	if (!(dir = opendir(dirname)))
		ft_error(dirname);
	while ((files = readdir(dir)))
	{
		if (files->d_name[0] != '.')
			ft_putendl(files->d_name);
	}
	closedir(dir);
}