/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 04:36:46 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/15 19:20:15 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char** line)
{
	int		i;
	int 	ret;
	int 	found;
	int 	count;
	char	buf[BUF_SIZE + 1];

	count = -1;
	if (fd < 0)
			return (-1);
	while (ft_isprint(line[i][0]))
		i++;
	while ((ret = read(fd, buf, BUF_SIZE)))
		buf[ret] = '\0';
	while (i > count++)
	{
		*buf += found;
		found = ft_search(buf);
		count += 2;
	}
	count -= 2;
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
