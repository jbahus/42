/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:11:17 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/16 21:09:19 by jbahus           ###   ########.fr       */
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
# define ZOOM 5
# define X_ORIGIN 100
# define Y_ORIGIN 100
# define CONST 0.7

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

#endif