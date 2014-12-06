/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/06 19:24:57 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_env *e, t_stock *lst)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	while (lst)
	{
		ft_putnbr(lst->nb);
		if (lst->prev)
		{
			if (lst->prev->nl == '\n')
			{
				ft_putchar('\n');
				y += 10;
				x = 0;
			}
		}
		if (lst->nb == 10)
			mlx_pixel_put(e->mlx, e->win, X_ORIGIN + x, (Y_ORIGIN + y + (lst->nb * ZOOM)), 0x00FF00);
		else
			mlx_pixel_put(e->mlx, e->win, X_ORIGIN + x, (Y_ORIGIN + y + (lst->nb * ZOOM)), 0xFF0000);
		x += 10;
		lst = lst->next;
	}
}

int		expose_hook(t_env *e)
{
	t_stock	*lst;

	lst = open_f(e);
	draw(e, lst);
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
