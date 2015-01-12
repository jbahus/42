/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:55:35 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/12 19:56:15 by jbahus           ###   ########.fr       */
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

void	draw_y(t_env *e, int ***coord, int i, int j)
{
	float	m;
	float 	p;
	int 	start;
	int 	y;
	int 	x;

	y = coord[i + 1][j][1] - coord[i][j][1];
	x = coord[i + 1][j][0] - coord[i][j][0];
	m = (float)y / (float)x;
	p = coord[i][j][1] - (m * coord[i][j][0]);
	ft_coord(&x, &start, coord[i][j][0], coord[i + 1][j][0]);
	while (x <start)
	{
		y = (int)((m * x + p) + 0.5);
		ft_pixel_put(e, x, y);
		x++;
	}
	ft_coord(&y, &start, coord[i][j][1], coord[i + 1][j][1]);
	while (y < start)
	{
		x = (int)((y - p) / m + 0.5);
		ft_pixel_put(e, x, y);
		y++;
	}
}

void	draw_x(t_env *e, int ***coord, int i, int j)
{
	float	m;
	float 	p;
	int 	start;
	int 	y;
	int 	x;

	y = coord[i][j + 1][1] - coord[i][j][1];
	x = coord[i][j + 1][0] - coord[i][j][0];
	m = (float)y / (float)x;
	p = coord[i][j][1] - (m *coord[i][j][0]);
	ft_coord(&x, &start, coord[i][j][0], coord[i][j + 1][0]);
	while (x <start)
	{
		y = (int)((m * x + p) + 0.5);
		ft_pixel_put(e, x, y);
		x++;
	}
	ft_coord(&y, &start, coord[i][j][1], coord[i][j + 1][1]);
	while (y < start)
	{
		x = (int)((y - p) / m + 0.5);
		ft_pixel_put(e, x, y);
		y++;
	}
}

void	init_y(t_env *e, int ***coord, int *x_y)
{
	int 	i;
	int 	x;
	int 	y;

	i = 1;
	x = 0;
	while (x < x_y[0])
	{
		y = 0;
		while (y < x_y[i])
		{
				draw_y(e, coord, x, y);
				y++;
		}
		i++;
		x++;
	}
}

void	init_x(t_env *e, int ***coord, int *x_y)
{
	int 	i;
	int 	x;
	int 	y;

	i = 1;
	x = 0;
	while (x < x_y[0])
	{
		y = 0;
		while (y < x_y[i])
		{
				draw_x(e, coord, x, y);
				y++;
		}
		i++;
		x++;
	}
}
