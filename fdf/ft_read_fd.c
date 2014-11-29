/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:55:24 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/30 00:13:01 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_stock	*stock__stock(char **ret, t_stock *prev);
t_stock	*node_create(int data, t_stock *prev);

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

/*void	ft_placeEOS(t_stock **end, t_stock *s)
{
	while (s && s->next)
		s = s->next;
	s->next = *end;
}*/

void	ft_create_tab(char *line)
{
	char		**ret;
	t_stock		*s;

	ret = (char**)ft_strnew(ft_strlen(line));
	ret = ft_strsplit(line, ' ');
	ft_putendl(*ret);
	s = node_create(ft_atoi(*ret), NULL);
	ret++;
	while(*ret != '\0')
	{
//		printf("%s", *ret);
		//s = (t_stock*)ft_memalloc(sizeof(t_stock));
		//s->nb = ft_atoi(*ret);
		//s = s->next;
		s = node_create(ft_atoi(*ret), s);
		ret++;
//		ret++;
	}
	printf("\n");
}

/*t_stock	*stock__stock(char **ret, t_stock *prev)
{
	if((ret != NULL))
       {
           t_stock *begin;
           begin = node_create(ft_atoi(*ret), prev);
           stock__stock(++ret, begin);
       }
    else if(ret == NULL)
       return (prev);
   return (prev);
}*/
       
t_stock	*node_create(int data, t_stock *prev)
    {
        t_stock	*temp;
        
        temp = (t_stock*)malloc(sizeof(t_stock));
        temp->nb = malloc(1);
        
        if (temp == '\0')
        {
            ft_putendl("Malloc failed (temp)\n");
            exit(0);
        }
        if (temp->nb == '\0')
        {
            ft_putendl("Malloc failed (data)\n");
            exit(0);
        }
        
		temp->nb = data;
        
        if (prev != NULL)
            prev->next = temp;
		temp->next = NULL;
        
        return (temp);
    }