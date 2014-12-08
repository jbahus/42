/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:26:16 by jbahus            #+#    #+#             */
/*   Updated: 2014/12/08 19:26:43 by jbahus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_stock *first_lst(int nb, char nl, t_stock *lst, int x, int y)
{
	lst = (t_stock*)malloc(sizeof(t_stock));
	lst->prev = NULL;
	lst->nl = nl;
	lst->x = (x + X_ORIGIN + (CONST * nb));
	lst->y = (y + Y_ORIGIN + ((CONST / 2) * nb));
	lst->z = nb;
	return (lst);
}

t_stock *ft_new_lst(int nb, char nl, t_stock *lst, t_stock *new_lst, int x, int y)
{
	new_lst = (t_stock*)malloc(sizeof(t_stock));
	new_lst->z = nb;
	new_lst->nl = nl;
	new_lst->x = (x + X_ORIGIN + (CONST * nb));
	new_lst->y = (y + Y_ORIGIN + ((CONST / 2) * nb));
	new_lst->prev = lst;
	new_lst->next = NULL;
	lst->next = new_lst;
	return (new_lst);
}