/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 02:04:47 by mroux             #+#    #+#             */
/*   Updated: 2014/03/09 23:29:18 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*tmp;
	char			*tmp2;
	size_t			i;
	unsigned char	var;

	i = 0;
	var = (unsigned char)c;
	tmp = (char *)s1;
	tmp2 = (char *)s2;
	while (i < n)
	{
		if (tmp2[i] == var)
		{
			tmp[i] = tmp2[i];
			i++;
			return (tmp + i);
		}
		tmp[i] = tmp2[i];
		i++;
	}
	return (NULL);
}
