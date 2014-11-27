/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:11:17 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/27 19:52:55 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "get_next_line.h"
# include <fcntl.h>

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
void	ft_create_tab(int **tab, char *line);

#endif