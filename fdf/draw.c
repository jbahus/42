/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:33:03 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/26 19:49:53 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_coord(int *x, int *start, int alpha, int beta)
{
	if (alpha < beta)
	{
		*x = alpha;
		*start = beta;
	}
	else
	{
		*x = beta;
		*start = alpha;
	}
}

void	draw_y(t_env *e, int i, int j)
{
	float	m;
	float	p;
	int		start;
	int		x;
	int		y;

	y = e->coord[i + 1][j][1] - e->coord[i][j][1];
	x = e->coord[i + 1][j][0] - e->coord[i][j][0];
	m = (float)y / (float)x;
	p = e->coord[i][j][1] - (m * e->coord[i][j][0]);
	ft_coord(&x, &start, e->coord[i][j][0], e->coord[i + 1][j][0]);
	while (x < start)
	{
		y = (int)((m * x + p) + 0.5);
		pixput(e, x, y, ft_color(e, e->coord[i][j][2], e->coord[i + 1][j][2]));
		x++;
	}
	ft_coord(&y, &start, e->coord[i][j][1], e->coord[i + 1][j][1]);
	while (y < start)
	{
		x = (int)((y - p) / m + 0.5);
		pixput(e, x, y, ft_color(e, e->coord[i][j][2], e->coord[i + 1][j][2]));
		y++;
	}
}

void	draw_x(t_env *e, int i, int j)
{
	float	m;
	float	p;
	int		start;
	int		x;
	int		y;

	y = e->coord[i][j + 1][1] - e->coord[i][j][1];
	x = e->coord[i][j + 1][0] - e->coord[i][j][0];
	m = (float)y / (float)x;
	p = e->coord[i][j][1] - (m * e->coord[i][j][0]);
	ft_coord(&x, &start, e->coord[i][j][0], e->coord[i][j + 1][0]);
	while (x < start)
	{
		y = (int)((m * x + p) + 0.5);
		pixput(e, x, y, ft_color(e, e->coord[i][j][2], e->coord[i][j + 1][2]));
		x++;
	}
	ft_coord(&y, &start, e->coord[i][j][1], e->coord[i][j + 1][1]);
	while (y < start)
	{
		x = (int)((y - p) / m + 0.5);
		pixput(e, x, y, ft_color(e, e->coord[i][j][2], e->coord[i][j + 1][2]));
		y++;
	}
}

void	init_x(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->line_col[0])
	{
		j = 0;
		while (j < e->line_col[i + 1] - 1)
			draw_x(e, i, j++);
		i++;
	}
}

void	init_y(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->line_col[0] - 1)
	{
		j = 0;
		while (j < e->line_col[i + 1] && j < e->line_col[i + 2])
			draw_y(e, i, j++);
		i++;
	}
}
