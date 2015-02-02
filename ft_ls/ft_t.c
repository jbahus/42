/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 18:38:04 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/02 18:54:42 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_t(const char *dirname)
{
	int		ret;
	struct stat	t_stat;

	while
	while ((ret = stat(dirname, t_stat)) == 0)
	{

	}
	if (ret == -1)
		ft_error(dirname);
}