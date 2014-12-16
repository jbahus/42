/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/16 21:09:17 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_env *e, int dx, int dy)
{
	int		x_y;

	while (dx >= 0)
		{
			//x_y = (int)(dy / dx);
			mlx_pixel_put(e->mlx, e->win, dx, dy, 0xFF0000);
			dx--;
		}
}

void	draw(t_env *e, int **tab)
{
	int		x;
	int		y;
	int 	dx;
	int		dy;

	x = 1;
	while(x <= tab[0][0])
	{
		y = 2;
		while (y <= tab[x][0])
		{
			dy = (((x * ZOOM) + X_ORIGIN + (CONST * tab[x][y])) - ((x * ZOOM) + X_ORIGIN + (CONST * tab[x][y - 1])));
			if ((x + 1) <= tab[0][0])
				dx = (((x * ZOOM) + X_ORIGIN + (CONST * tab[x + 1][y])) - ((x * ZOOM) + X_ORIGIN + (CONST * tab[x][y])));
			ft_draw_line(e, dx, dy);
			//ft_draw_col(e,
			y++;
		}
		x++;
	}
}

int		expose_hook(t_env *e)
{
	int		**tab;

	tab = open_f(e);
	draw(e, tab);
	return (0);
}

int		key_hook(int key_code)
{
	ft_putnbr(key_code);
	ft_putchar('\n');
	if (key_code == 65307)
		exit(0);
	return (0);
}
