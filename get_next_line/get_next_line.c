/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 04:36:46 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/18 02:37:31 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int const fd, char** line)
{
	int		i;
	int 	ret;
	int 	found;
	int 	count;
	char	buf[BUF_SIZE + 1];

	printf("%c", 'C');
	count = -1;
	if (fd < 0)
			return (-1);
	printf("%c", 'D');
	while (ft_isprint(line[i][0]))
		i++;
	while ((ret = read(fd, buf, BUF_SIZE)))
		{
			printf("%s", buf);
			buf[ret] = '\0';
		}
	while (i > count++)
	{
		found = 0;
		found = ft_search(buf);
		*buf += found;
		*buf += 2;
	}
	line[i] = ft_strncpy(line[i], buf, found);
	if (!ft_strcount((const char**)line, ret))
		return (0);
	return (1);
}

int 	ft_search(char *buf)
{
	int 	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	i--;
	return (i);
}

int 	ft_strcount(const char **line, int nb)
{
	int 	i;

	i = 0;
	while (*line[i])
		i++;
	if (i < nb)
		return (1);
	return (0);
}
