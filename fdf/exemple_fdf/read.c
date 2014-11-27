/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:22:30 by mroux             #+#    #+#             */
/*   Updated: 2014/04/27 19:57:29 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fdf.h"
#include "libft/libft.h"

static void		final(char **line1, int y, t_env *e)
{
	t_xyz		point;
	int			x;

	if (line1[1] == '\0')
		return ;
	x = 0;
	while (line1[x] && line1[x][0] != '\n')
	{
		point.x1 = ZOOM * x + ZOOM * y + ORIGINE_X;
		point.y1 = ORIGINE_Y - (ZOOM * x) / 3 + (ZOOM * y) / 3;
		point.y1 -= 2 * ft_atoi(line1[x]);
		if (line1[x + 1])
		{
			point.x2 = ZOOM * (x + 1) + ZOOM * y + ORIGINE_X;
			point.y2 = ORIGINE_Y - (ZOOM * (x + 1)) / 3 + ZOOM * y / 3;
			point.y2 -= 2 * ft_atoi(line1[x + 1]);
		}
		ligne(e, &point);
		x++;
	}
}

static void		ord(t_xyz *point, char **line, int x, int y)
{
	point->x2 = ZOOM * x + ZOOM * y + ORIGINE_X;
	point->y2 = ORIGINE_Y - (ZOOM * x) / 3 + (ZOOM * y) / 3;
	point->y2 -= 2 * ft_atoi(line[x]);
}

static void		conver_point(char **line1, char **line2, int y, t_env *e)
{
	t_xyz		point;
	int			x;
	int			x2;

	x = 0;
	x2 = 0;
	if (!line1)
		final(line2, y, e);
	else if (!line2)
		final(line1, y, e);
	while (line1[x])
	{
		point.x1 = ZOOM * x + ZOOM * y + ORIGINE_X;
		point.y1 = ORIGINE_Y - (ZOOM * x) / 3 + (ZOOM * y) / 3;
		point.y1 -= 2 * ft_atoi(line1[x]);
		if (line2[x2] != '\0')
		{
			ord(&point, line2, x2++, y + 1);
			ligne(e, &point);
		}
		if (line1[x + 1])
			ord(&point, line1, x + 1, y);
		ligne(e, &point);
		x++;
	}
}

static int		reader_ini(int fd, char **line, char ***line1, char ***line2)
{
	int			ret;

	ret = get_next_line(fd, line);
	if (ret >= 0)
	{
		*line1 = ft_strsplit(*line, ' ');
		free(*line);
	}
	if (ret > 0)
	{
		ret = get_next_line(fd, line);
		*line2 = ft_strsplit(*line, ' ');
		if (*line && ret > 0)
			free(*line);
	}
	return (ret);
}

void			reader(int fd, t_env *e)
{
	char		*line;
	char		**line1;
	char		**line2;
	int			ret;
	int			i;

	i = 0;
	ret = reader_ini(fd, &line, &line1, &line2);
	if (line1 == NULL)
		return ;
	if (ret > 0)
		conver_point(line1, line2, i++, e);
	else
		final(line1, i++, e);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (!ret)
			break ;
		conver_point(line2, ft_strsplit(line, ' '), i++, e);
		free(line2);
		line2 = ft_strsplit(line, ' ');
		free(line);
	}
	final(line2, i, e);
}
