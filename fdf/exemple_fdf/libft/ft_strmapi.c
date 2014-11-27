/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:29:03 by mroux             #+#    #+#             */
/*   Updated: 2013/11/30 17:45:25 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	ptr = ft_strdup(s);
	while (ptr[i] != 0)
	{
		ptr[i] = f(i, ptr[i]);
		i++;
	}
	return (ptr);
}
