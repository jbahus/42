/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 05:03:42 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/02 18:54:40 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <errno.h>

typedef struct		s_opt
{
	int 	l;
	int 	R;
	int 	a;
	int 	r;
	int 	t;
}			t_opt;

typedef struct dirent t_dir;

void	ft_error(const char *str);
void	ft_ls(char *dirname);
void	ft_a(char *dirname);
void	get_opt(char *av, t_opt *opt);

#endif