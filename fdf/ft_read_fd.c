/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:55:24 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/27 20:48:24 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		open_f(char *fname)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(fname, O_RDONLY);
	if (!fd)
		return (0);
	i = 0;
	while (line)
	{
		get_next_line(fd, &line);
		free(line);
	}
	printf("%i", tab[0][0]);
	close(fd);
	return (0);
}

void	ft_create_tab(int **tab, char *line)
{
	
}