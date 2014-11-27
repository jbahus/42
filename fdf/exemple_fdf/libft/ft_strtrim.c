/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:51:35 by mroux             #+#    #+#             */
/*   Updated: 2014/04/15 15:08:30 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;

	str = (char *)malloc(*s);
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s);
	while (len-- && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		if (!(str = ft_strsub(s, 0, len + 1)))
			return (str);
	return (str);
}
