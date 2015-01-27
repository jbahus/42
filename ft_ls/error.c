/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:42:31 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/27 19:09:13 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(const char *str)
{
	ft_putstr("ft_ls: ");
	if (!str)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
	}
	else
		perror(str);
	exit (0);
}
