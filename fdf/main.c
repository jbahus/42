/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:10:26 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/08 19:26:45 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	e;

	/*if (ac < 4)
	{
		ft_putstr("\nwrong param:\n\n1st: File Name.\n2nd: Bottom Color (0xRRGGBB).\n3rd: Middle Color (0xRRGGBB).\n\n");
		return (0);
	}*/
	if (ac < 1)
		return (0);
	e.fname = av[1];
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "fdf");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}