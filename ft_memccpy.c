/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:38:54 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/06 18:05:45 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dest;
	const char	*s;
	size_t		i;

	i = 0;
	dest = dst;
	s = src;
	while (n > i && s[i - 1] != c)
	{
		dest[i] = s[i];
		i++;
		if (i == n)
			return (NULL);
	}
	i++;
	dst += i;
	return (dst);
}
