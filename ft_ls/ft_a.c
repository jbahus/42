/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:50:25 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/02 18:54:41 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_a(char *dirname)
{
	DIR		*dir;
	t_dir	*files;

	if (!(dir = opendir(dirname)))
		ft_error(dirname);
	while ((files = readdir(dir)))
		ft_putendl(files->d_name);
	closedir(dir);
}