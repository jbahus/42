/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:03:14 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/19 20:03:50 by jbahus           ###   ########.fr       */
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
	t_tls	*tls;

	tls = get_name(av, opt);
	if (opt.t == 1 || opt.R == 1 || opt.l == 1)
			tls = get_stats(tls, opt);
	if (opt.l == 1 || opt.R == 1 || opt.a == 1 || opt.r == 1 || opt.t == 1)
	{
		if (opt.a == 1)
			ft_a(tls);
		if (opt.t == 1)
			ft_t(tls);
		if (opt.r == 1)
			ft_r(tls);
		if (opt.R == 1)
			ft_R(av, tls, opt);
		/*if (opt.l == 1)
			ft_l(av);*/
		if (ret == 1)
			ft_putchar('\n');
	}
	else
	{
		ft_ls(tls);
		if (ret == 1)
			ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_opt	opt;

	i = 1;
	if (ac > 1)
	{
		while (av[i] && (av[i][0] == '-') && (ft_strcmp(av[i], "--") != 0))
			get_opt(av[i++], &opt);
		if (ft_strcmp(av[i], "--") == 0)
			i++;
	}
	if (i >= ac)
		ft_go_to(NULL, opt, 0);
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