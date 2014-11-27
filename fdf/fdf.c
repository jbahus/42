/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/27 19:52:39 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*draw(void *mlx, void *win)
{
	int 	x;
	int 	y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0x0000FF);
			x++;
		}
		y++;
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