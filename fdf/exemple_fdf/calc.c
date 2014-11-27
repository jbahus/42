/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:02:54 by mroux             #+#    #+#             */
/*   Updated: 2014/04/27 19:55:10 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "libft/libft.h"

void			affichage(t_env *e, int x, int y)
{
	if (x >= 0 && x <= 2000 && y >= 0 && y <= 1200)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x9657CF);
}

void			change(int *x1, int *y1, int *x2, int *y2)
{
	int		var;

	var = *x1;
	*x1 = *y1;
	*y1 = var;
	var = *x2;
	*x2 = *y2;
	*y2 = var;
}

int				absolute(int x)
{
	if (x < 0)
		x = x * (-1);
	return (x);
}
