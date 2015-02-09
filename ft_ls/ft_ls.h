/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 05:03:42 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/09 18:46:03 by jbahus           ###   ########.fr       */
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

typedef struct			s_tls
{
	char				*f_name;
	int					mtime;
	int					isdir;
	struct s_tls		*next;
}						t_tls;

typedef struct			s_opt
{
	int 				l;
	int 				R;
	int 				a;
	int 				r;
	int 				t;
}						t_opt;

typedef struct dirent	t_dir;
typedef struct stat		t_stat;

void					ft_error(const char *str);
void					ft_ls(char *dirname);
void					ft_a(char *dirname);
void					ft_t(const char *dirname);
void					ft_r(char *dirname);
void					ft_R(const char *dirname);
void					get_opt(char *av, t_opt *opt);
void					aff_ls(t_tls *tls, int r);
t_tls					*new_tls(t_tls *tls);
void					rev_order(t_tls **tmp, t_tls **next);

#endif