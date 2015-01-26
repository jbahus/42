/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:11:17 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/26 19:53:36 by jbahus           ###   ########.fr       */
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
	void			*mlx;
	void			*win;
	void			*img;
	char			*fname;
	int				*line_col;
	int				***coord;
	int				move_x;
	int				move_y;
	int				zoom;
	float			hight;
	int				min_max;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
}					t_env;

void				ft_error(const char *str);
void				split(char *tmp, t_env *e);
void				init_x(t_env *e);
void				init_y(t_env *e);
void				pixput(t_env *e, int x, int y, unsigned int color);
void				max_min(t_env *e);
void				get_coord(t_env *e);
unsigned int		ft_color(t_env *e, int z1, int z2);

#endif
