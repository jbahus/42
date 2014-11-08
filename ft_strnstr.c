/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:43:25 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/05 19:39:19 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (*s1 && i < (int)n)
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
		{
			i = i - j;
			s1 += i;
			return ((char*)s1);
		}
		i = i - j + 1;
	}
	return (NULL);
}
