/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:11:17 by jbahus            #+#    #+#             */
/*   Updated: 2015/01/18 22:03:46 by jbahus           ###   ########.fr       */
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
	int		*line_col;
	int		***coord;
	int 	move_x;
	int 	move_y;
	int 	zoom;
	float	hight;
	float	pivote;
}					t_env;

void	ft_error(const char *str);
void	split(char *tmp, t_env *e);
void	init_x(t_env *e);
void	init_y(t_env *e);
void	ft_pixel_put(t_env *e, int x, int y, int z1, int z2);

#endif