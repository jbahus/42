/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:31:13 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/05 16:05:35 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*s;
	size_t		i;

	dest = dst;
	s = src;
	i = 0;
	while (len > i)
	{
		dest[i] = s[i];
		i++;
	}
	return (dst);
}
