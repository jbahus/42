/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:55:24 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/29 03:46:57 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		open_f(char *fname)
{
	int		fd;
	char	*line;
	//int 	*tab;

	fd = open(fname, O_RDONLY);
	if (!fd)
		return (0);
	line = NULL;
	while (get_next_line(fd, &line))
	{
	//	get_next_line(fd, &line);
	//	tab = ft_memalloc(ft_strlen(line));
		//printf("%s\n", line);
		ft_create_tab(line);
		free(line);
	}
	//printf("%i", tab[0]);
	close(fd);
	return (0);
}

void	ft_create_tab(char *line)
{
	char	**ret;
	int 	i;

	i = 0;
	ret = (char**)ft_strnew(ft_strlen(line));
	ret = ft_strsplit(line, ' ');
	while(*ret != '\0' && i < 19)
	{
		i = 0;
		printf("%s", *ret);
		ret++;
	}
	printf("\n");
	/*while (ret)
	{
		while (*ret)
			*tab[i++] = ft_atoi(*ret++);
		ret++;
	}*/
}