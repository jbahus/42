/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:23:43 by mroux             #+#    #+#             */
/*   Updated: 2013/12/01 16:52:50 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			cmp;
	unsigned char	*ptr;

	cmp = 0;
	ptr = (unsigned char *)s;
	while (cmp < n && n > 0)
	{
		ptr[cmp] = 0;
		cmp++;
	}
}
