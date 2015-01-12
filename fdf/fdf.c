/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:08:15 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/12 20:03:31 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_c(int *x, int *y, int *map, int **tab)
{
	float	tmp;

	tmp = 15. + (35. + map[2]) * (0.82 * map[0] + 0.60 * map[1]);
	*x = (int)(tmp + 0.5);
	tmp = 0.60 * (0.60 * map[0] - 0.82 * map[1]);
	tmp -= 0.05 * tab[map[0]][map[1]];
	//tmp *= (35. + map[2]);
	tmp += 533.;
	*y = (int)(tmp + 0.5);
}

int 	*ft_x_y(int **tab)
{
	int 	*x_y;
	int 	i;

	x_y = (int*)malloc(sizeof(x_y) * (tab[0][0] + 1));
	i = 0;
	x_y[i++] = tab[0][0];
	while (i <= x_y[0])
	{
		x_y[i] = tab[i][0];
		i++;
	}
	return (x_y);
}

int		***init_coord(int **tab)
{
	int 	***coord;
	int 	i[2];

	if (!(coord = (int***)malloc(sizeof(coord) * (tab[0][0] + 1))))
		return (NULL);
	i[0] = 1;
	while (i[0] <= tab[0][0])
	{
		if (!(coord[i[0]] = (int**)malloc(sizeof(*coord) * (tab[i[0]][0] + 1))))
			return (NULL);
		i[1] = 1;
		while (i[1] <= tab[i[0]][0])
		{
			if (!(coord[i[0]][i[1]] = (int*)malloc(sizeof(coord) * 2)))
				return (NULL);
			ft_init_c(&coord[i[0]][i[1]][0], &coord[i[0]][i[1]][1], i, tab);
			i[1]++;
		}
		i[0]++;
	}
	return(coord);
}

int		expose_hook(t_env *e)
{
	int 	*x_y;
	int		**tab;
	int 	***coord;

	tab = open_f(e);
	coord = init_coord(tab);
	x_y = ft_x_y(tab);
	init_y(e, coord, x_y);
	init_x(e, coord, x_y);
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
