/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:53:39 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/05 19:05:59 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return ((char*)s1);
	while (*s1 != '\0')
	{
		j = 0;
		while (s1[i] == s2[j] || s2[j] == '\0')
		{
			if (s2[j] == '\0')
				return ((char*)s1);
			j++;
			i++;
		}
		s1++;
	}
	return (NULL);
}
