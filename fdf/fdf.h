/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:11:17 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/01 22:20:02 by jbahus           ###   ########.fr       */
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
# define ZOOM 3

typedef struct		s_stock
{
	int 			nb;
	struct s_stock	*next;
	struct s_stock	*prev;
}					t_stock;

typedef	struct		s_env
{
	void	*mlx;
	void	*win;
}					t_env;

void	init();
int		expose_hook(t_env *e);
int 	key_hook(int key_code);
void	*draw(void *mlx, void *win);
int		open_f(char *fname);
void	ft_error(const char *str);

#endif