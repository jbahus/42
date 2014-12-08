/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:11:17 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/08 19:26:41 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# define ZOOM 10
# define X_ORIGIN 50
# define Y_ORIGIN 50
# define CONST 0.6

typedef struct		s_stock
{
	int 			z;
	int 			x;
	int 			y;
	char			nl;
	struct s_stock	*next;
	struct s_stock	*prev;
}					t_stock;

typedef	struct		s_env
{
	void	*mlx;
	void	*win;
	char	*fname;
}					t_env;

int		expose_hook(t_env *e);
int 	key_hook(int key_code);
t_stock	*open_f(t_env *e);
void	ft_error(const char *str);
t_stock *first_lst(int nb, char nl, t_stock *lst, int x, int y);
t_stock *ft_new_lst(int nb, char nl, t_stock *lst, t_stock *new_lst, int x, int y);

#endif