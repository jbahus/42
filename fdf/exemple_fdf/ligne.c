/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:00:44 by mroux             #+#    #+#             */
/*   Updated: 2014/04/27 17:58:45 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		first(t_env *e, t_xyz *point)
{
	int			d;
	int			incx;
	int			x;
	int			y;

	if (point->y1 > point->y2)
		change(&point->x1, &point->x2, &point->y1, &point->y2);
	incx = point->x2 > point->x1 ? 1 : -1;
	d = 2 * absolute(point->x2 - point->x1) - (point->y2 - point->y1);
	x = point->x1;
	y = point->y1;
	affichage(e, x, y);
	while (y++ <= point->y2)
	{
		if (d >= 0)
		{
			x = x + incx;
			d += 2 * (absolute(point->x2 - point->x1) -
				(point->y2 - point->y1));
		}
		else
			d = d + 2 * absolute(point->x2 - point->x1);
		affichage(e, x, y);
	}
}

static void		second(t_env *e, t_xyz *point)
{
	int			d;
	int			incy;
	int			x;
	int			y;

	if (point->x1 > point->x2)
		change(&point->x1, &point->x2, &point->y1, &point->y2);
	incy = point->y2 > point->y1 ? 1 : -1;
	d = 2 * absolute(point->y2 - point->y1) - (point->x2 - point->x1);
	x = point->x1;
	y = point->y1;
	affichage(e, x, y);
	while (x++ <= point->x2)
	{
		if (d >= 0)
		{
			y = y + incy;
			d += 2 * (absolute(point->y2 - point->y1) -
				(point->x2 - point->x1));
		}
		else
			d = d + 2 * absolute(point->y2 - point->y1);
		affichage(e, x, y);
	}
}

void			ligne(t_env *e, t_xyz *point)
{
	if (absolute(point->x2 - point->x1) < absolute(point->y2 - point->y1))
		first(e, point);
	else
		second(e, point);
}
