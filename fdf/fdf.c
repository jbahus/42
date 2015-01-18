/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/18 22:12:35 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_env *e, int x, int y, int z1, int z2)
{
	if (z1 <= 0 || (z1 <= 0 && z2 <= 0))
		mlx_pixel_put(e->mlx, e->win, (x + e->move_x), (y + e->move_y), 0x3366CC);
	if (z1 >= 10)
		mlx_pixel_put(e->mlx, e->win, (x + e->move_x), (y + e->move_y), 0x996600);
	if (z1 < z2 || z2 < z1)
		mlx_pixel_put(e->mlx, e->win, (x + e->move_x), (y + e->move_y), 0x00CC00);
}

void	get_coord(int z, t_env *e, int i, int j)
{
	float	tmp;

	e->coord[i][j] = (int*)malloc(sizeof(int*) * 3);
	tmp = 15. + (35. + e->zoom) * ((0.82 + e->pivote) * i + (0.60 - e->pivote) * j);
	e->coord[i][j][0] = (int)(tmp + 0.5);
	tmp = (0.60 - e->pivote) * ((0.60 - e->pivote) * i - (0.82 + e->pivote) * j);
	tmp -= 0.05 * (z * e->hight);
	tmp *= (35. + e->zoom);
	tmp += 533.;
	e->coord[i][j][1] = (int)(tmp + 0.5);
	e->coord[i][j][2] = (z * e->hight);
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
