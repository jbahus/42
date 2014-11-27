/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:27:25 by mroux             #+#    #+#             */
/*   Updated: 2014/04/27 20:02:36 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
#include "fdf.h"
#include "libft/libft.h"

static int		expose_hook(t_env *e)
{
	int		fd;

	fd = open(e->argv, O_RDONLY);
	if (fd == -1)
	{
		perror(e->argv);
		exit(0);
	}
	reader(fd, e);
	return (0);
}

static int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int				main(int argc, char const *argv[])
{
	t_env	e;

	if (argc > 1)
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 2000, 1200, "fdf");
		e.argv = ft_strdup(argv[1]);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		write(1, "WTF MAN, USE FDF LIKE THIS : ./fdf [AMAZING MAP]\n", 50);
	return (0);
}
