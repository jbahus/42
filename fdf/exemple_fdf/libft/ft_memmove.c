/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 04:09:37 by mroux             #+#    #+#             */
/*   Updated: 2013/11/30 20:40:30 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*ss1;
	const char	*ss2;
	char		tmp[n];
	size_t		i;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (const char *)s2;
	while (i < n)
	{
		tmp[i] = ss2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		ss1[i] = tmp[i];
		i++;
	}
	return (s1);
}
