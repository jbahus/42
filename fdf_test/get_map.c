/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:11:42 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/16 14:58:39 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_test.h"

int		*get_map(char *str, int *map)
{
	int		i;
	char	**ret;

	i = 0;
	ret = ft_strsplit(str, ' ');
	if (!ret)
		return (map);
	while (ret[i])
		i++;
	map = malloc(sizeof(int) * i);
	i = 0;
	while (ret[i])
	{
		map[i] = ft_atoi(ret[i]);
		i++;
	}
	free(ret);
	return (map);
}

int		*ft_intcpy(int *ret, int *map)
{
	int 	i;

	i = 0;
	while (map[i])
			i++;
	ret = (int*)malloc(sizeof(int*) * i);
	i = 0;
	while (map[i])
	{
		ret[i] = map[i];
		i++;
	}
	return (ret);
}

int		**fat_realloc(int **map)
{
	int		i;
	int		**ret;

	i = 0;
	ret = NULL;
	//ft_putendl("trololo");
	if (!map)
	{
		ret = (int**)malloc(sizeof(int**));
		return (ret);
	}
	ft_putendl("trololo");
	while (map[i])
		i++;
	ret = (int**)malloc(sizeof(int**) * (i));
	i = 0;
	while (map[i])
	{
		ret[i] = ft_intcpy(ret[i], map[i]);
		i++;
	}
	free(map);
	return (ret);
}

int 	main(int argc, char const **argv)
{
	int		fd;
	char	*line;
	int		**map;
	int		i;

	i = 0;
	map = NULL;
	if (!argc)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		map = fat_realloc(map);
		map[i] = get_map(line, map[i]);
		free(line);
		i++;
	}
	return (0);
}
