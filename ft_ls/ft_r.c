/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:06:25 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/19 20:08:13 by jbahus           ###   ########.fr       */
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

void	ft_r(t_tls *tls)
{
	while (tls->next)
	{
		if (tls->f_name[0] != '.')
			ft_putendl(tls->f_name);
		tls = tls->next;
	}
}