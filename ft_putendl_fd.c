/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:57:51 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/06 18:00:24 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	*str;

	str = s;
	i = 0;
	while (str[i] != '\0')
		ft_putchar_fd(str[i++], fd);
	ft_putchar_fd('\n', fd);
}
