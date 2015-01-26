/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 22:04:38 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/26 19:55:26 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_color(t_env *e, int z1, int z2)
{
	if ((z1 <= e->min_max * 0.10 && z2 >= e->min_max * 0.65) ||
		(z1 >= e->min_max * 0.10 && z1 <= e->min_max * 0.65) ||
		(z2 <= e->min_max * 0.10 && z1 >= e->min_max * 0.65))
		return (0x00CC00);
	else if (z1 <= e->min_max * 0.10)
		return (0x3366CC);
	else if (z1 >= e->min_max * 0.65)
		return (0x996600);
	return (0);
}

void			ft_error(const char *str)
{
	ft_putstr("fdf: ");
	if (!str)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
	}
	else
		perror(str);
	exit (0);
}

void			max_min(t_env *e)
{
	int		i;
	int		j;
	int		min;
	int		max;

	i = 0;
	min = e->coord[0][0][2];
	max = e->coord[0][0][2];
	while (i < e->line_col[0])
	{
		j = 0;
		while (j < e->line_col[i + 1])
		{
			if (min > e->coord[i][j][2])
				min = e->coord[i][j][2];
			if (max < e->coord[i][j][2])
				max = e->coord[i][j][2];
			j++;
		}
		i++;
	}
	e->min_max = min + max;
}
