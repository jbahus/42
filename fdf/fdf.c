/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/05 18:56:51 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void colone(int x, int y, t_env *e)
{
	int 	c;

	c = 105;
	while(c)
	while(y <= 305)
	{
		x = 105;
		while(x <= 305)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
			x++;
		}
		y += 20;
	}
}

void line(int x, int y, t_env *e)
{
	while(x <= 305)
	{
		y = 105;
		while(y <= 305)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
			y++;
		}
		x += 20;
	}
}

void	*draw(t_env *e)
{
	int		x;
	int		y;
	int 	i;

	x = 105;
	y = 105;
	line(x, y, e);
	colone(x, y, e);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		key_hook(int key_code)
{
	ft_putnbr(key_code);
	ft_putchar('\n');
	if (key_code == 53)
		exit(0);
	return (0);
}

void	init(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "fdf");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
