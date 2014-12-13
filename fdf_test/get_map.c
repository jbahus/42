/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 15:11:42 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/13 18:53:29 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_test.h"

int		*get_map(char *str, int *map)
{
	int		i;
	int		j;
	char	**ret;

	j = 0;
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
		map[j] = ft_atoi(ret[i]);
		j++;
	}
	return (map);
}

char	**fat_realloc(char **str)
{
	int		i;
	char	**ret;

	i = 0;
	if (str == NULL)
	{
		ret = (char**)malloc(sizeof(char**));
		return (ret);
	}
	while (str[i])
		i++;
	ret = (char**)malloc(sizeof(char**) * (i + 1));
	i = 0;
	while (str[i])
	{
		ret[i] = (char*)malloc(sizeof(char*) * ft_strlen(str[i]));
		ret[i] = ft_strcpy(ret[i], str[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int 	main(int argc, char const **argv)
{
	int		fd;
	char	*ret;
	char	**tmp;
	//int		**map;
	int		i;

	i = 0;
	tmp = NULL;
	//map = NULL;
	if (!argc)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &ret))
	{
		tmp = fat_realloc(tmp);
		tmp[i] = (char*)malloc(sizeof(char*) * ft_strlen(ret) + 1);
		tmp[i] = ft_strcpy(tmp[i], ret);
		//map[i] = get_map(ret, map[i]);
		i++;
	}
	i = 0;
	while (tmp[i])
		ft_putendl(tmp[i++]);
	return (0);
}
