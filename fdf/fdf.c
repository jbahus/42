/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/15 19:34:26 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_env *e, int x, int y)
{
	mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
}

void	get_coord(int z, t_env *e, int i, int j)
{
	float	tmp;

	e->coord[i][j] = (int*)malloc(sizeof(int*) * 2);
	tmp = 15. + 35. * (0.82 * i + 0.60 * j);
	e->coord[i][j][0] = (int)(tmp + 0.5);
	tmp = 0.60 * (0.60 * i - 0.82 * j);
	tmp -= 0.05 * z;
	tmp *= 35.;
	tmp += 533.;
	e->coord[i][j][1] = (int)(tmp + 0.5);
}

void	split2(char *tmp, t_env *e, int line)
{
	char	**ret;
	int		column;
	int		i;

	column = 0;
	i = 0;
	if (!(ret = ft_strsplit(tmp, ' ')))
		return ;
	while (ret[column])
		column++;
	e->line_col[line + 1] = column;
	e->coord[line] = (int**)malloc(sizeof(int**) * (column + 1));
	while (ret[i])
	{
		get_coord(ft_atoi(ret[i]), e, line, i);
		i++;
	}
}

void	split(char *tmp, t_env *e)
{
	char	**ret;
	int		lines;
	int		i;

	lines = 0;
	i = 0;
	if (!(ret = ft_strsplit(tmp, '\n')))
		return ;
	while (ret[lines])
		lines++;
	e->line_col = (int*)malloc(sizeof(int*) * (lines + 1));
	e->line_col[0] = lines;
	e->coord = (int***)malloc(sizeof(int***) * (lines + 1));
	while (ret[i])
	{
		split2(ret[i], e, i);
		i++;
	}
}
