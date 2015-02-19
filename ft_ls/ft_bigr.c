/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:05:32 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/19 20:05:46 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_R(char *av, t_tls *tls, t_opt opt)
{
	ft_ls(tls);
	while (tls->next)
	{
		if (tls->isdir == 1 && tls->f_name[0] != '.')
		{
			if (!av)
			{
				ft_putchar('\n');
				ft_putstr(ft_strjoin(".", ft_strjoin("/", tls->f_name)));
				ft_putendl(":");
				ft_go_to(ft_strjoin(".", ft_strjoin("/", tls->f_name)), opt, 1);
			}
			else
			{
				ft_putchar('\n');
				ft_putstr(ft_strjoin(av, ft_strjoin("/", tls->f_name)));
				ft_putendl(":");
				ft_go_to(ft_strjoin(av, ft_strjoin("/", tls->f_name)), opt, 1);
			}
		}
		tls = tls->next;
	}
}