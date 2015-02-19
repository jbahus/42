/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:06:16 by jbahus            #+#    #+#             */
/*   Updated: 2015/02/19 20:07:55 by jbahus           ###   ########.fr       */
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
void					ft_ls(t_tls *tls);
void					ft_a(t_tls *tls);
void					ft_t(t_tls *tls);
void					ft_r(t_tls *tls);
void					ft_R(char *av, t_tls *tls, t_opt opt);
void					ft_l(char *dirname);
void					trie_t(t_tls **tls);
void					ft_go_to(char *av, t_opt opt, int ret);
t_tls					*get_stats(t_tls *tls, t_opt opt);
t_tls					*get_name(char *dirname, t_opt opt);
void					get_opt(char *av, t_opt *opt);
void					aff_ls(t_tls *tls, int r);
t_tls					*new_tls(t_tls *tls);
void					rev_order(t_tls **tmp, t_tls **next);
void					ft_write_t(t_tls *tls);

#endif