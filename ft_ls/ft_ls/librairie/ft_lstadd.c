/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:01:14 by jbahus            #+#    #+#             */
/*   Updated: 2014/11/13 04:17:24 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*first;
	t_list	*ptr;

	if(!new)
		return ;
	if (!alst)
	{
		ptr->next = NULL;
		first = ptr;
	}
	else
	{
		first = *alst;
		ptr = new;
		ptr->next = first;
		first = ptr;
	}
}
