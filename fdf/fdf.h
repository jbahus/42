/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:11:17 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/12 19:55:04 by jbahus           ###   ########.fr       */
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
# include <math.h>
# define ZOOM 20
# define X_ORIGIN 100
# define Y_ORIGIN 100
# define CONST 0.9
# define SPACE 10

typedef	struct		s_env
{
	void	*mlx;
	void	*win;
	char	*fname;
}					t_env;

int		expose_hook(t_env *e);
int 	key_hook(int key_code);
int		**open_f(t_env *e);
void	ft_error(const char *str);
void	init_x(t_env *e, int ***coord, int *x_y);
void	init_y(t_env *e, int ***coord, int *x_y);
void	ft_pixel_put(t_env *e, int x, int y);

#endif