/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 02:57:14 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/18 05:17:22 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_option(char c, char opt)
{
	if (c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't')
		opt = c;
}

int		ft_valid(char *str, char *opt)
{
	int		i;

	i = 0;
	while (str[i])
		ft_option(str[i], opt[i]);
	if (opt[0] == '\0')
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*opt;

	opt = ft_strnew(6);
	i = 1;
	while(i <= argc)
		if (ft_valid(argv[i++], opt))
			ft_putstr("error");
	ft_putstr(opt);
	return (0);
}