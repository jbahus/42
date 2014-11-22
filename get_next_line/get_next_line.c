/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 04:36:46 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/22 18:14:27 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char** line)
{
	int 	ret;
	int 	found;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			found = ft_search(buf);
			tmp = ft_strnew(found);
			*line = ft_strjoin(*line, ft_strncpy(buf, tmp, found));
			free(tmp);
		}
	if (ret <= 0)
		return (-1);
	return (1);
}

int 	ft_search(const char *buf)
{
	int 	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	i--;
	return (i);
}