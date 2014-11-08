/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:57:27 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/06 17:55:50 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	char	*str;
	int		i;

	str = s;
	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}
