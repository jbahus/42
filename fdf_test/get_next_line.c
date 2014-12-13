/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 22:21:35 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/24 22:21:40 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read_fd(char **stay, int fd)
{
	char	*buf;
	int		ret;

	buf = ft_strnew(BUFF_SIZE + 1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	*stay = ft_strjoin(*stay, buf);
	ft_strdel(&buf);
	return (ret);
}

int		ft_fill(char **line, char **stay, char *ptr)
{
	int		ret;

	ret = 0;
	if (*ptr == '\n')
		ret = 1;
	*ptr = 0;
	*line = ft_strjoin("", *stay);
	*stay = ft_strjoin(ptr + 1, "");
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	static char		*stay;
	char			*ptr;
	int				size;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (stay == 0)
		stay = "";
	size = BUFF_SIZE;
	while (1)
	{
		ptr = stay;
		while (*ptr || size < BUFF_SIZE)
		{
			if (*ptr == '\n' || *ptr == -1 || *ptr == 0)
				return (ft_fill(line, &stay, ptr));
			ptr++;
		}
		size = ft_read_fd(&stay, fd);
		if (size == -1)
			return (-1);
	}
	return (0);
}
