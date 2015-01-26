/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:10:26 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/26 20:02:50 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_f(t_env *e)
{
	int		fd;
	int		ret;
	char	*line;
	char	*tmp;

	if ((fd = open(e->fname, O_RDONLY)) == -1)
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

	get_coord(e);
	init_x(e);
	init_y(e);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		key_hook(int key_code, t_env *e)
{
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
	if (key_code == 65453 && (e->zoom - 2) >= -32)
		e->zoom -= 2;
	if (key_code == 65365)
		e->hight += 1.2;
	if (key_code == 65366)
		e->hight -= 1.2;
	if (key_code == 65307)
		exit(0);
	ft_bzero(e->data, (sizeof(char) * 1500 * 1000 * (e->bpp / 8)));
	expose_hook(e);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac < 2)
	{
		ft_putendl("don't forget the map ;)");
		return (0);
	}
	e.zoom = 0;
	e.hight = 1.;
	e.move_x = 0;
	e.move_y = 0;
	e.fname = av[1];
	open_f(&e);
	max_min(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1500, 1000, av[1]);
	e.img = mlx_new_image(e.mlx, 1500, 1000);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	mlx_key_hook(e.win, &key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
