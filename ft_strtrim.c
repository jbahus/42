/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:31:19 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/07 19:49:34 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	frt;
	size_t	bck;

	frt = 0;
	bck = ft_strlen(s) - 1;
	while (s[frt] == ' ' || s[frt] == '\n' || s[frt] == '\t')
		frt++;
	while (s[bck] == ' ' || s[bck] == '\n' || s[bck] == '\t')
		bck--;
	return (ft_strsub(s, frt, (bck - frt)));
}
