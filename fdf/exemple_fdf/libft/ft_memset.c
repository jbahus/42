/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:13:31 by mroux             #+#    #+#             */
/*   Updated: 2014/03/09 23:29:39 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cmp;
	unsigned char	*ptr;

	cmp = 0;
	ptr = (unsigned char *)b;
	while (cmp < len)
	{
		ptr[cmp] = (unsigned char)c;
		cmp++;
	}
	return (b);
}
