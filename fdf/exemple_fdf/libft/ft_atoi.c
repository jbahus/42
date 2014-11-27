/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <mroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:35:16 by mroux             #+#    #+#             */
/*   Updated: 2013/11/26 02:55:40 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		neg;

	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == 32)
		str++;
	neg = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
		result = (result * 10) + (*str++ - '0');
	return (result * neg);
}
