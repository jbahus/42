/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:10:26 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/15 19:35:38 by jbahus           ###   ########.fr       */
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

int		key_hook(int key_code)
{
	ft_putnbr(key_code);
	ft_putchar('\n');
	if (key_code == 65307)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac < 1)
		return (0);
	e.fname = av[1];
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1500, 1000, av[1]);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
