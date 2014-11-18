/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 01:06:45 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/15 15:57:40 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "/nfs/zfs-student-3/users/2014/jbahus/1er_annee/get_next_line/librairie/libft.h"
# define BUF_SIZE 32

int		get_next_line(int const fd, char** line);
int 	ft_search(char *buf);
int 	ft_strcount(const char **line, int nb);

#endif
