/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 16:59:10 by mroux             #+#    #+#             */
/*   Updated: 2014/05/08 06:45:42 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ZOOM 5
# define ORIGINE_X 100
# define ORIGINE_Y 600

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*argv;
}					t_env;

typedef struct		s_xyz
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				h1;
	int				h2;
}					t_xyz;

void				ligne(t_env *e, t_xyz *point);
void				reader(int fd, t_env *e);
void				affichage(t_env *e, int x, int y);
void				change(int *x1, int *y1, int *x2, int *y2);
int					absolute(int x);

#endif
