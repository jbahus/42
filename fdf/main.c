/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:10:26 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/18 21:35:47 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_f(t_env *e)
{
	int		fd;
	int		ret;
	char	*line;
	char	*tmp;

	if (!(fd = open(e->fname, O_RDONLY)))
		ft_error(e->fname);
	tmp = ft_strnew(1);
	while ((ret = get_next_line(fd, &line)))
	{
		tmp = ft_strjoin(tmp, line);
		tmp = ft_strjoin(tmp, "\n");
		free(line);
	}
	close(fd);
	if (ret == -1)
		ft_error(e->fname);
	split(tmp, e);
	ft_strdel(&tmp);
}

int		expose_hook(t_env *e)
{
	int		**tab;

	open_f(e);
	init_x(e);
	init_y(e);
	return (0);
}

int		key_hook(int key_code, t_env *e)
{
	ft_putnbr(key_code);
	ft_putchar('\n');
	if (key_code == 65361)
		e->move_x -= 15;
	if (key_code == 65362)
		e->move_y -= 15;
	if (key_code == 65363)
		e->move_x += 15;
	if (key_code == 65364)
		e->move_y += 15;
	if (key_code == 65451)
		e->zoom += 2;
	if (key_code == 65453)
	{
		if ((e->zoom - 2) >= -32)
			e->zoom -= 2;
	}
	if (key_code == 65365)
		e->hight += 1.2;
	if (key_code == 65366)
		e->hight -= 1.2;
	if (key_code == 65450)
		e->pivote += 0.2;
	if (key_code == 65455)
		e->pivote -= 0.2; 
	if (key_code == 65307)
		exit(0);
	mlx_clear_window(e->mlx, e->win);
	expose_hook(e);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac < 1)
		return (0);
	e.zoom = 0;
	e.pivote = 0.;
	e.hight = 1.;
	e.move_x = 0;
	e.move_y = 0;
	e.fname = av[1];
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1500, 1000, av[1]);
	mlx_key_hook(e.win, &key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
