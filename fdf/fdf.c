/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/29 03:37:53 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*draw(void *mlx, void *win)
{
	int 	x;
	int 	y;
	int 	R;
	int 	G;
	int 	B;

	//B = 0x000000;
	//R = 0x000000;
	y = 100;
	while (y < 200)
	{
		G = 0x005000;
		R = 0x500000;
		B = 0x000000;
		x = 100;
		while (x < 200)
		{
			if (x == y)
				B += 0x000002;
			mlx_pixel_put(mlx, win, x, y, (R + G + B));
			x++;
			G += 0x000200;
		}
		y++;
		R += 0x010000;
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int 	key_hook(int key_code)
{
	ft_putnbr(key_code);
	ft_putchar('\n');
	if (key_code == 65307)
		exit(0);
	return (0);
}

void	init()
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "fdf");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}