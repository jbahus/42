/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:18:47 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/07 16:49:31 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	char	*str;
	int		i;
	int		j;
	int		nbstr;

	nbstr = 1;
	i = -1;
	str = (char*)s;
	if(str[i] != c)
		nbstr++;
	while (str[i++])
		if (str[i] != c && str[i + 1] != c)
			nbstr++;
	ret = (char**)malloc(sizeof(char**) * nbstr);
	i = 0;
	while (i < nbstr)
		ret[i++] = ft_strnew(ft_strlen(str));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		j = 0;
		printf("d\n");
		while (*str != c && *str != '\0')
		{
			ret[i][j++] = *str++;
			printf("q\n");
		}
		while (*str == c && *str != '\0')
		{
			printf("c\n");
			str++;
		}
		i++;
	}
	return (ret);
}
