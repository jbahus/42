/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:11:17 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/06 19:24:58 by jbahus           ###   ########.fr       */
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
# define X_ORIGIN 30
# define Y_ORIGIN 30

typedef struct		s_stock
{
	int 			nb;
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

#endif