/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:58:20 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/05 21:19:00 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = ft_strdup(s2);
	i = ft_strlen(s1);
	while (j < n)
	{
		s1[i + j] = str[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
