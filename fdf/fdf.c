/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/26 19:49:52 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put_img(t_env *e, int x, int y, unsigned int color)
{
	int				i;
	unsigned char	clr[(e->bpp / 8) - 1];

	i = 0;
	while (i < ((e->bpp / 8) - 1))
	{
		clr[i] = color >> (i * 8);
		i++;
	}
	while (i >= 0)
	{
		e->data[y * e->sizeline + x * e->bpp / 8 + i] = clr[i];
		i--;
	}
}

void	pixput(t_env *e, int x, int y, unsigned int color)
{
	if (x + e->move_x >= 0 && x + e->move_x < 1500 &&
		y + e->move_y >= 0 && y + e->move_y <= 1000)
		ft_pixel_put_img(e, (x + e->move_x), (y + e->move_y), color);
}

void	get_coord(t_env *e)
{
	float	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < e->line_col[0])
	{
		j = 0;
		while (j < e->line_col[i + 1])
		{
			tmp = 15. + (35. + e->zoom) * (0.82 * i + 0.60 * j);
			e->coord[i][j][0] = (int)(tmp + 0.5);
			tmp = 0.60 * (0.60 * i - 0.82 * j);
			tmp -= 0.05 * (e->coord[i][j][2] * e->hight);
			tmp *= (35. + e->zoom);
			tmp += 533.;
			e->coord[i][j][1] = (int)(tmp + 0.5);
			j++;
		}
		i++;
	}
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
		e->coord[line][i] = (int*)malloc(sizeof(int*) * 3);
		e->coord[line][i][2] = ft_atoi(ret[i]);
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
