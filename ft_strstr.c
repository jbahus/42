/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:53:39 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/09 23:35:32 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *str1;
	const char *str2;

	if (s2 == NULL)
		return ((char *)s1);
	while (*s1 != '\0')
	{
		str1 = s1;
		str2 = s2;
		while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
