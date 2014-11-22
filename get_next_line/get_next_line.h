/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 01:06:45 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/22 18:09:25 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "librairie/libft.h"
# define BUFF_SIZE 32

int		get_next_line(int const fd, char** line);
int 	ft_search(const char *buf);

#endif
