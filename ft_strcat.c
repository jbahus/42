/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:18:59 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/05 21:09:58 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = strdup(s2);
	i = ft_strlen(s1);
	while (str[j] != '\0')
	{
		s1[i + j] = str[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
