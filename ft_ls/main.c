/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 02:57:14 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/09 18:46:00 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_opt(char *av, t_opt *opt)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (av[i] != 'l' && av[i] != 'R' && av[i] != 'a' && av[i] != 'r' && av[i] != 't')
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(av[i]);
			ft_putchar('\n');
			ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
			exit(0);
		}
		i++;
	}
	if (ft_memchr(av, 'l', ft_strlen(av)) != NULL)
		opt->l = 1;
	if (ft_memchr(av, 'R', ft_strlen(av)) != NULL)
		opt->R = 1;
	if (ft_memchr(av, 'a', ft_strlen(av)) != NULL)
		opt->a = 1;
	if (ft_memchr(av, 'r', ft_strlen(av)) != NULL)
		opt->r = 1;
	if (ft_memchr(av, 't', ft_strlen(av)) != NULL)
		opt->t = 1;
}

int		ft_ind(char **av, int i)
{
	static int	ret;

<<<<<<< HEAD
=======

>>>>>>> b105d9395973e2e29253a855ddb7d0c235997429
	if (av[i + 1] || ret == 1)
	{
		ft_putstr(av[i]);
		ft_putstr(":\n");
		return (ret = 1);
	}
	return (ret = 0);
}

void	ft_go_to(char *av, t_opt opt, int ret)
{
	if (opt.l == 1 || opt.R == 1 || opt.a == 1 || opt.r == 1 || opt.t == 1)
	{
		if (opt.a == 1)
			ft_a(av);
<<<<<<< HEAD
		if (opt.t == 1)
			ft_t(av);
		if (opt.r == 1)
			ft_r(av);
=======
>>>>>>> b105d9395973e2e29253a855ddb7d0c235997429
		if (ret == 1)
			ft_putchar('\n');
	}
	else
	{
		ft_ls(av);
		if (ret == 1)
			ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_opt	opt;
	t_path	path;

	i = 1;
	if (ac > 1)
	{
		while (av[i] && (av[i][0] == '-') && (ft_strcmp(av[i], "--") != 0))
			get_opt(av[i++], &opt);
		if (ft_strcmp(av[i], "--") == 0)
			i++;
	}
	if (i >= ac)
		ft_go_to("./", opt, 0);
	else
	{
		while (av[i])
		{
			ft_go_to(av[i], opt, ft_ind(av, i));
			i++;
		}
	}
	return (0);
}
